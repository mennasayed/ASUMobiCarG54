#include <SoftwareSerial.h>

SoftwareSerial HC06(0,1);//TX,RX
float T;
String hi="";
char s;
char path;
unsigned int integerValue = 0;

char value;
char vvv;
char v;
int motorA1=2;
int motorA2=3;
int motorB1=4;
int motorB2=5;
int enA =9;
int enB =10; 
int data1,data2,data3;
int sensorA = 6;
int sensorB = 7;
int sensorC = 8;
int carspeed;

int d;
int theta;

int trigPin = 11;    
int echoPin = 12;    
long duration, cm;
void setup() {

 // put your setup code here, to run once:

Serial.begin(9600);
HC06.begin(9600);

pinMode(motorA1,OUTPUT);
pinMode(motorA2,OUTPUT);
pinMode(motorB1,OUTPUT);
pinMode(motorB2,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
analogWrite (enA, 250);
analogWrite (enB,250);


}
void distanceF (int x){
  float t = x/70.1;
  t=t*1000;
 forward();Serial.println(t);
 delay (t);
Stop();
  }
 void angle (int y){
float t2 = (y/360.0)* 1.26;
t2=t2*1000;
right();Serial.println(t2);
delay (t2);
Stop();
 }
 
      
 void forward ()
 {   digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
 analogWrite (enA,250);
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

//=======================================================

//========================================================
 void right ()
 { digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,200);
 analogWrite (enB,200);}

  void right2 ()
 { digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,0);
 analogWrite (enB,150);}

void left (){ digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,HIGH);
analogWrite (enA,200);
 analogWrite (enB,200);}



 void left2 (){ digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,HIGH);
analogWrite (enA,150);
 analogWrite (enB,0);}
 
void Stop (){  digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,LOW);
 analogWrite (enA,0);
 analogWrite (enB,0);}




    void rectangle2(){
      
      for (int i=0;i<4;i++)

      {distanceF(60);
      Stop();delay(500);
      angle(90);
     Stop();delay(500);
      }
      }
    
void circle ()
{
   digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,150);
 analogWrite (enB,250);
 delay(4100*2);
  
  }
  void infinity ()
{
  delay (2000);
    digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,100);
 analogWrite (enB,200);
 delay(4500/2);
 
  digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,200);
 analogWrite (enB,100);
   delay(3600);
    digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,100);
 analogWrite (enB,200);
 delay(4800/2);
 Stop();
   delay(5000);
  }
  
  

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

 value= Serial.read();

 
 if(value=='F')//forward

 {forward();}

 else if(value=='B') //backward

 {back();}

 else if (value=='R')//turn right

 {right ();}

 else if(value=='L')//turn left

 {left();}

else if(value=='W'){
while(1)
{
 vvv= Serial.read(); 
 if (vvv=='U'){break;}
 
 
data1 =digitalRead(sensorA);
data2 =digitalRead(sensorB);
data3 =digitalRead(sensorC);


Serial.print("data1  =  ");
Serial.println(data1);
Serial.print("data2  =  ");
Serial.println(data2);
Serial.print("data3  =  ");
Serial.println(data3);
if ((data1==HIGH)&&(data2==LOW)&&(data3==HIGH))forward2();
if ((data1==LOW)&&(data2==HIGH)&&(data3==HIGH))left2();
if ((data1==HIGH)&&(data2==HIGH)&&(data3==LOW))right2();
if ((data1==LOW)&&(data2==LOW)&&(data3==HIGH))left2();
if ((data1==HIGH)&&(data2==LOW)&&(data3==LOW))right2();
}
}

 if (value== 'D')
 {
  int x = hat();
  Serial.println(x);
  distanceF (x);
  }
 if (value== 'A')
 {
   int x = hat();
  Serial.println(x);
  angle (x);
  }
if (value== 'Z')
{
  
  delay(25000);
  // put your main code here, to run repeatedly:
  rectangle2 ();
  Stop();
delay(25000);
circle ();
  Stop();

delay(25000);
infinity();
  }
if (value=='Q'){rectangle2();}
 else if (value=='S')//stop
{Stop();}

 }



