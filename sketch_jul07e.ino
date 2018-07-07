int d;
int theta;

int trigPin = 11;    
int echoPin = 12;    
long duration, cm;
void setup() {


 
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
