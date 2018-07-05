#include<NewPing.h>
int motorA1=2;
int motorA2=3;
int motorB1=4;
int motorB2=5;
int enA =9;
int enB =10; 
# define TRIGGER_PIN 13
#define ECHO_PIN 12
#define MAX_DISTANCE 200
NewPing sonar (TRIGGER_PIN, ECHO_PIN,MAX_DISTANCE);
void setup(){
  Serial.begin(115200);
  pinMode(motorA1,OUTPUT);
pinMode(motorA2,OUTPUT);
pinMode(motorB1,OUTPUT);
pinMode(motorB2,OUTPUT);
analogWrite (enA, 250);
analogWrite (enB,250);
}
   void Stop (){ 
  digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,LOW);}
    
     void forward ()
 {   digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
 analogWrite (enA,255);
 analogWrite (enB,255);}

  
  void loop (){
    
  Serial.print ("Ping: ");
  Serial.print (sonar.ping_cm());
  Serial.println ("cm");
  if ((sonar.ping_cm()>=10))
  {forward ();}
  else
  {Stop();
    delay (30);
  } }
