void angle (int y){
float t2 = (y/360)* T;
right();
  delay (t2);
forward ();
delay(8000);Stop();
 }
 void angle2 (int z){float t2 = (z/360)* T;
right();
  delay (t2);}
      
 void forward ()
 {   digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
 analogWrite (enA,255);
 analogWrite (enB,255);}

  void forward2 ()
 { digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
 analogWrite (enA,160);
 analogWrite (enB,160);}

