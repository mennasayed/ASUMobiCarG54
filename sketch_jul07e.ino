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

void rectangle () {
      for(int i=0;i<4;i++){
forward();
delay (1000);
delay(1000);
right();
delay (900);
Stop();
delay(1000);}
    }
+void circle ()
{
  digitalWrite(motorA1,HIGH);
}
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,160);
 analogWrite (enB,250);
 delay(5000*2);
  
  }
