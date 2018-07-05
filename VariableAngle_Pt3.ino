void Stop ()
{  
  digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,LOW);
 digitalWrite(motorB1,LOW);
 digitalWrite(motorB2,LOW);
 }

  void right ()
 {  
  digitalWrite(motorA1,LOW);
 digitalWrite(motorA2,HIGH);
 digitalWrite(motorB1,HIGH);
 digitalWrite(motorB2,LOW);
 analogWrite (enA,0);
 analogWrite (enB,120);}
 oid angle2 (int z){float t2 = (z/360)* 2.387;
   t2=t2*1000;
right();
  delay (500);
  }
