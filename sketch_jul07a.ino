
+#include <SoftwareSerial.h>
+
+SoftwareSerial HC06(0,1);//TX,RX
+float T=2.9;
+String hi="";
+char s;
+char path;
+unsigned int integerValue = 0;
+
+char value;
+char vvv;
+char v;
+int motorA1=2;
+int motorA2=3;
+int motorB1=4;
+int motorB2=5;
+int enA =9;
+int enB =10; 
+int data1,data2,data3;
+int sensorA = 6;
+int sensorB = 7;
+int sensorC = 8;
+int carspeed;
+
+int d;
+int theta;
+
+int trigPin = 11;    
+int echoPin = 12;    
+long duration, cm;
+void setup() {
+
+ // put your setup code here, to run once:
+
+Serial.begin(9600);
+HC06.begin(9600);
+
+pinMode(motorA1,OUTPUT);
+pinMode(motorA2,OUTPUT);
+pinMode(motorB1,OUTPUT);
+pinMode(motorB2,OUTPUT);
+  pinMode(trigPin, OUTPUT);
+  pinMode(echoPin, INPUT);
+analogWrite (enA, 250);
+analogWrite (enB,250);
+
+
+}
+
+
+  void infinity ()
+{
+  delay (2000);
+    digitalWrite(motorA1,HIGH);
+ digitalWrite(motorA2,LOW);
+ digitalWrite(motorB1,HIGH);
+ digitalWrite(motorB2,LOW);
+analogWrite (enA,100);
+ analogWrite (enB,200);
+ delay(4500/2);
+ 
+  digitalWrite(motorA1,HIGH);
+ digitalWrite(motorA2,LOW);
+ digitalWrite(motorB1,HIGH);
+ digitalWrite(motorB2,LOW);
+analogWrite (enA,200);
+ analogWrite (enB,100);
+   delay(3800);
+    digitalWrite(motorA1,HIGH);
+ digitalWrite(motorA2,LOW);
+ digitalWrite(motorB1,HIGH);
+ digitalWrite(motorB2,LOW);
+analogWrite (enA,100);
+ analogWrite (enB,200);
+ delay(5000/2);
+ Stop();
+   delay(5000);
+  }
+
+   int hat (){
+  hi="";
+  int i=1;
+    while (i==1)
+
+    {
+        if (Serial.available() > 0)
+
+      {
+        s= Serial.read(); 
+         if(s=='E')
+      {
+        i=0;
+      }
+      else
+      {
+        hi+=s;
+      }
+      }
+    }
+    int dist = hi.toInt();
+    return dist;
+  }
+
+void loop() {
+
+ // put your main code here, to run repeatedly:
+ 
+ value= Serial.read();
+
+ if(value=='F')//forward
+
+ {forward();
+ }
+
+ else if(value=='B') //backward
+
+ {back();}
+
+ else if (value=='R')//turn right
+
+ {right ();}
+
+ else if(value=='L')//turn left
+
+ {left();}
+
+
+
+
+else if(value=='W'){
+while(1)
+{
+ vvv= Serial.read(); 
+ if (vvv=='U'){break;}
+ 
+ 
+data1 =digitalRead(sensorA);
+data2 =digitalRead(sensorB);
+data3 =digitalRead(sensorC);

