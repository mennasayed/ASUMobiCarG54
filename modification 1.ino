#include <SoftwareSerial.h>

SoftwareSerial HC06(0,1);//TX,RX

char value;

int motorA1=2;
int motorA2=3;
int motorB1=4;
int motorB2=5;
int enA =9;
int enB =10; 

void setup() {

 // put your setup code here, to run once:

Serial.begin(9600);
HC06.begin(9600);

pinMode(motorA1,OUTPUT);
pinMode(motorA2,OUTPUT);
pinMode(motorB1,OUTPUT);
pinMode(motorB2,OUTPUT);

analogWrite (enA, 250);
analogWrite (enB,250);


}

void loop() {

 // put your main code here, to run repeatedly:
 
 value= Serial.read();

 if(value=='F')//forward

 {
  
 digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
 analogWrite (enA , 250);
analogWrite (enB , 250);
 }

 else if(value=='B') //backward

 {

 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,HIGH);
analogWrite (enA , 250);
analogWrite (enB , 250);
 }

 else if (value=='R')//turn right

 {

 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA , 250);
analogWrite (enB,50);
 }

 else if(value=='L')//turn left

 {

 digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,HIGH);
analogWrite (enA,50);
analogWrite (enB, 250);
 }

 else if (value=='S')//stop

 {

 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,LOW);
analogWrite (enA,0);
analogWrite (enB,0);
 }

 }


