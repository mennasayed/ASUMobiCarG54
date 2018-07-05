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

void forward ()
 {   digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
 analogWrite (enA,255);
 analogWrite (enB,255);}

//move for a certain distance
void distanceF (int x){
  float t = x/72.0;
  t=t*1000;
 forward();
 delay (t);
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
if (value== 'D')
 {
  int x = hat();
  Serial.println(x);
  distanceF (x);
  }



}
