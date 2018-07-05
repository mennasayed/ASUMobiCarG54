#include <SoftwareSerial.h>

SoftwareSerial HC06(0,1);//TX,RX

char value;

int motorA1=2;
int motorA2=3;
int motorB1=4;
int motorB2=5;
int enA =9;
int enB =10; 
int sensorA = 6;
int sensorB = 7;
int sensorC = 8;
int data1,data2,data3;
int carspeed;
float T;
int d;
int theta;
void setup() {

 // put your setup code here, to run once:

Serial.begin(9600);
HC06.begin(9600);

pinMode(motorA1,OUTPUT);
pinMode(motorA2,OUTPUT);
pinMode(motorB1,OUTPUT);
pinMode(motorB2,OUTPUT);
pinMode(sensorA,INPUT);
pinMode(sensorB,INPUT); 
pinMode(sensorC,INPUT);
analogWrite (enA, 250);
analogWrite (enB,250);


}
void distanceF (int x){
  float t = x/carspeed;
  t=t*1000;
 forward();
 delay (t);
Stop();
  }
 void angle (int y){
float t2 = (y/360)* T;
right();
  delay (t2);
forward ();
 }

 void forward ()
 {   digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
 analogWrite (enA,255);
 analogWrite (enB,255);}

  void forward2 ()
 { digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
 analogWrite (enA,160);
 analogWrite (enB,160);}

void back (){ 
  digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,HIGH);
digitalWrite (enA , HIGH);
digitalWrite (enB , HIGH);}

 void right ()
 { digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,0);
 analogWrite (enB,255);}

  void right2 ()
 { digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,0);
 analogWrite (enB,80);}

void left (){ digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,HIGH);
analogWrite (enA,255);
 analogWrite (enB,0);}

 void left2 (){ digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,HIGH);
analogWrite (enA,80);
 analogWrite (enB,0);}

void Stop (){  digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,LOW);}
 
void loop() {

 // put your main code here, to run repeatedly:
value= Serial.read(); 

Serial.print(value);
if(value=='F')//forward
{forward();}

 else if(value=='B') //backward
{back();}

 else if (value=='R')//turn right
{right();}


 else if(value=='L')//turn left
{left();}


else if(value=='W'){
while(1)
{
  value= Serial.read();
data1 =digitalRead(sensorA);
data2 =digitalRead(sensorB);
data3 =digitalRead(sensorC);


Serial.print("data1  =  ");
Serial.println(data1);
Serial.print("data2  =  ");
Serial.println(data2);
Serial.print("data3  =  ");
Serial.println(data3);
if ((data1==HIGH)&&(data2==LOW)&&(data3==HIGH))forward();
if ((data1==LOW)&&(data2==HIGH)&&(data3==HIGH))left2();
if ((data1==HIGH)&&(data2==HIGH)&&(data3==LOW))right2();
if ((data1==LOW)&&(data2==LOW)&&(data3==HIGH))left2();
if ((data1==HIGH)&&(data2==LOW)&&(data3==LOW))right2();



else if (value=='G')break;
 
 }}

if (value=='J')
{
d=Serial.read();
  distanceF(d);  }

 if (value =='H'){
  theta = Serial.read();
  angle (theta);}
  
  else//stop

 {Stop();}
 
 }



