// 无聊的盒子
//使用mg90s舵机
#include <Servo.h> 
Servo myservo;  //创建一个舵机控制对象

int close_pos = 110;    // 该变量用与存储舵机能够关闭钮子开关的角度
int home_pos = 20;      // 回正角度

int pin_on = 2;
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9);  // 该舵机由arduino第九脚控制
  myservo.write(home_pos); 
  pinMode(pin_on,INPUT_PULLUP);

  randomSeed(analogRead(0));//随机数种子
} 

void case_1(){
  // 快进快出
  
  myservo.write(close_pos); 
  delay(300);
  myservo.write(home_pos); 
  delay(300); 
}

void case_2(){
  //中速
  delay(500);
  myservo.write(close_pos); 
  delay(500);
  myservo.write(home_pos); 
  delay(1000); 
}

void case_3(){
  //低速
  delay(500);
  myservo.write(close_pos); 
  delay(1000);
  myservo.write(home_pos); 
  delay(1000); 
}

void case_4(){
  //疲惫
  int pos;
  for(pos = home_pos; pos<=close_pos-20; pos+=1)   
  {                                
    myservo.write(pos);        
    delay(30);                      
  } 
  myservo.write(close_pos); 
  delay(1000);
  myservo.write(home_pos);
  delay(500);
}

void case_5(){
  //生气
  int pos;
  for(pos = home_pos; pos<=close_pos-20; pos+=1)   
  {                                
    myservo.write(pos);        
    delay(10);                      
  } 
  for(pos = close_pos-20; pos>=home_pos+30; pos-=1)   
  {                                
    myservo.write(pos);        
    delay(10);                      
  }
  myservo.write(close_pos); 
  delay(1000);
  myservo.write(home_pos);
  delay(500);
}

void loop() 
{  
  int randNumber = random(5);
  if(digitalRead(2)==0){
  switch(randNumber){
    case 0:case_1();break;
    case 1:case_2();break;
    case 2:case_3();break;
    case 3:case_4();break;
    case 4:case_5();break;
      
  }
 }
}

