int motorA1=2;
int motorA2=3;
int motorB1=4;
int motorB2=5;
int enA =9;
int enB =10; 
int i=0;int j=0;
int data1,data2,data3;
int sensorA = 6;
int sensorB = 7;
int sensorC = 8;
int carspeed;
float T;
int d;
int theta;
void setup() {
  // put your setup code here, to run once:
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

 void Stop (){  digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,LOW);}
  void right ()
 {  digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,0);
 analogWrite (enB,120);}

void distanceF (int x){
  float t = x/20;
  t=t*1000;
 forward();
 delay (t);
Stop();
  }
   
   void angle2 (int z){float t2 = (z/360)* 2.387;
   t2=t2*1000;
right();
  delay (500);}
    
    void rectangle () {
      for(int i=0;i<4;i++){
forward();
delay (1000);
Stop();
delay(1000);
right();
delay (900);
Stop();
delay(1000);}
    }
void circle ()
{
   digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,160);
 analogWrite (enB,250);
 delay(5000*2);
  
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
   delay(3800);
    digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,100);
 analogWrite (enB,200);
 delay(5000/2);
 Stop();
   delay(5000);
  }
void loop() {
delay(5000);
  // put your main code here, to run repeatedly:
  rectangle ();
  Stop();
delay(5000);
circle ();
  Stop();

delay(5000);
infinity();
}
