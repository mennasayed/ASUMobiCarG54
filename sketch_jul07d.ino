#include <SoftwareSerial.h>

SoftwareSerial HC06(0,1);//TX,RX
float T=2.9;
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
