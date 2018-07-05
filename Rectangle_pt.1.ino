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
void setup()
{
  // put your setup code here, to run once:
pinMode(motorA1,OUTPUT);
pinMode(motorA2,OUTPUT);
pinMode(motorB1,OUTPUT);
pinMode(motorB2,OUTPUT);

analogWrite (enA, 250);
analogWrite (enB,250);

}
