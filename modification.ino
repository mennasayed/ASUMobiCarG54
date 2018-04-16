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
void setup() {

 // put your setup code here, to run once:

Serial.begin(9600);


pinMode(motorA1,OUTPUT);
pinMode(motorA2,OUTPUT);
pinMode(motorB1,OUTPUT);
pinMode(motorB2,OUTPUT);
pinMode(sensorA,INPUT);
pinMode(sensorB,INPUT); 
pinMode(sensorC,INPUT);
analogWrite (enA, 50);
analogWrite (enB,50);


}

void loop() {

 // put your main code here, to run repeatedly:
 
data1 =digitalRead(sensorA);
data2 =digitalRead(sensorB);
data3 =digitalRead(sensorC);


Serial.print("data1  =  ");
Serial.println(data1);
Serial.print("data2  =  ");
Serial.println(data2);
Serial.print("data3  =  ");
Serial.println(data3);

if ((data1==HIGH)&&(data2==LOW)&&(data3==HIGH))value='F';
if ((data1==LOW)&&(data2==HIGH)&&(data3==HIGH))value='L';
if ((data1==HIGH)&&(data2==HIGH)&&(data3==LOW))value='R';
if ((data1==LOW)&&(data2==LOW)&&(data3==HIGH))value='L';
if ((data1==HIGH)&&(data2==LOW)&&(data3==LOW))value='R';

 if(value=='F')//forward
{
  
 digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,100);
 analogWrite (enB,100);
 }

 else if(value=='B') //backward

 {

 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,HIGH);
digitalWrite (enA , HIGH);
digitalWrite (enB , HIGH);
 }

 else if (value=='R')//turn right

 {

 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,0);
 analogWrite (enB,80);

 }

 else if(value=='L')//turn left

 {

 digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,HIGH);
analogWrite (enA,80);
 analogWrite (enB,0);

 }
 else//stop

 {

 digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,LOW);

 }

 }



