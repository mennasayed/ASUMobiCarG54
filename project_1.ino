#include <SoftwareSerial.h>
SoftwareSerial HC05(0,1);//TX,RX
char value;
int motorA1=2;
int motorA2=3;
int motorB1=4;
int motorB2=5;
int LDR =8;
int photointerupt= 13;
int Line =9;
void setup() {
 // put your setup code here, to run once:
pinMode(motorA1,OUTPUT);
pinMode(motorA2,OUTPUT);
pinMode(motorB1,OUTPUT);
pinMode(motorB2,OUTPUT);
pinMode (6,OUTPUT);//LEDS
pinMode (7,OUTPUT);
pinMode (12,OUTPUT);
//pinMode (13,OUTPUT);//LEDS
pinMode (10,OUTPUT);
pinMode (Line,INPUT);
pinMode (LDR,INPUT);
pinMode(photointerupt,INPUT);
Serial.begin(9600);
HC05.begin(9600);
}
void loop() {
 // put your main code here, to run repeatedly:
 Serial.println(digitalRead(photointerupt));
 if (digitalRead(photointerupt)==0)
 {
 if(HC05.available())
 {
 value=HC05.read();
 Serial.println(value);

 if(value=='F')//forward
 {
 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,HIGH);
 }
 else if(value=='B') //backward
 {
 digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
 }
 else if (value=='R')//turn right
 {
 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
 }
 else if(value=='L')//turn left
 {
 digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,HIGH);
 }
 else if (value=='S')//stop
 {
 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,LOW);
 }
 }
 else {
 // Serial.println(digitalRead(Line));
 if (digitalRead(Line)==0)
 {
 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,HIGH);
 }
 else {
 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,LOW);
 }
 if (digitalRead (LDR) ==0)
 {
 digitalWrite(6,HIGH);
 digitalWrite(7,HIGH);
 digitalWrite(12,HIGH);
 digitalWrite(13,HIGH);
 }
 else {digitalWrite(6,LOW); digitalWrite(7,LOW); digitalWrite(12,LOW); digitalWrite(13,LOW);}
 Serial.println (analogRead(A0));
 if (analogRead(A0) > 100)
 {
 digitalWrite (10,HIGH);
 }
 else {(digitalWrite (10,LOW));}
 }
 }
}
