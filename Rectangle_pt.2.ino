void forward ()
 {   digitalWrite(motorA1,HIGH);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
 analogWrite (enA,255);
 analogWrite (enB,255);}

 void Stop ()
 {  digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,LOW);
 }
  void right ()
 {  digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
analogWrite (enA,0);
 analogWrite (enB,120);
 }


