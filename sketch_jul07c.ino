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
+void distanceF (int x){
+  float t = x/20;
+  t=t*1000;
+ forward();
+ delay (t);
+Stop();
+  }
+ void angle (int y){
+float t2 = (y/360)* T;
+right();
+  delay (t2);
+forward ();
+delay(8000);Stop();
+ }
