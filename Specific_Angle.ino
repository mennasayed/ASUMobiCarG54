#include <SoftwareSerial.h>

SoftwareSerial HC06(0,1);//TX,RX
char value;
String hi="";
char s;
char path;
unsigned int integerValue = 0;
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

 void right ()
 { digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,200);
 analogWrite (enB,200);}

//move for a certain angle
 void angle (int y){
float t2 = (y/360.0)* 1.25;
t2=t2*1000;
right();Serial.println(t2);
delay (t2);
Stop();
 }
  void Stop (){  digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,LOW);}

 int hat (){
  hi="";
  int i=1;
    while (i==1)

    {
        if (Serial.available() > 0)

      {
        s= Serial.read(); 
         if(s=='E')
      {
        i=0;
      }
      else
      {
        hi+=s;
      }
      }
    }
    int dist = hi.toInt();
    return dist;
  }

 
void loop() {
  // put your main code here, to run repeatedly:
if (value== 'A')
 {
  int x = hat();
  Serial.println(x);
 angle (x);
  }



}
