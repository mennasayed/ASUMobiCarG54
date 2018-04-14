#include<NewPing.h>
const int trigger=5;
const int echo=2;
NewPing ultrasonic(trigger,echo);
void setup() {
Serial.begin(9600);
pinMode(9,OUTPUT);
pinMode(6,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}
  
  // put your setup code here, to run once:
}

void loop() {
  
  // put your main code here, to run repeatedly:

 forward();
  analogWrite(9,255);
  analogWrite(6,255);
digitalWrite(5,0);
delayMicroseconds(2);
digitalWrite(5,1);
delayMicroseconds(10);
digitalWrite(5,0);
 float d=ultrasonic.ping_cm();
  if (d<=30)
{ 
 right();
 delay(1000);
 forward();
 d=ultrasonic.ping_cm();
  if(d<=30)
  {
 right();
 delay(1000);
 forward();
}
  else {
  forward();
}
}
else {
   forward();
}
}
void forward()
{
   digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH); 
  digitalWrite(10,LOW);
}
void right()
{
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
 digitalWrite(11,LOW); 
  digitalWrite(10,HIGH); 
}
