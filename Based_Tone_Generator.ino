void setup()
{
                for (int i=0;i<8;i++)
                {
                pinMode(i, INPUT_PULLUP);//take pins0-7 as inputs with default high or pulled up pins.
                }
                pinMode(9,OUTPUT);//buzzer output at pin9
}
 
// the loop routine runs over and over again forever:
void loop()
{
                if (digitalRead(0)==LOW)
                {
                                analogWrite(9,25);//if button 1 is pressed PWM of duty ratio(25*100)/255 is given to buzzer
                                delay(100);
                                analogWrite(9,0);
                }
                if (digitalRead(1)==LOW)
                {
                                analogWrite(9,50); //if button 2 is pressed PWM of duty ratio(50*100)/255 is given to buzzer
 
                                delay(100);
                                analogWrite(9,0);
                }
                if (digitalRead(2)==LOW)
                {
                                analogWrite(9,75);// /if button 3 is pressed PWM of duty ratio(75*100)/255 is given to buzzer
 
                                delay(100);
                                analogWrite(9,0);
                }
                if (digitalRead(3)==LOW)
                {
                                analogWrite(9,100); //if button 4 is pressed PWM of duty ratio(100*100)/255 is given to buzzer
 
                                delay(100);
                                analogWrite(9,0);
                }
                if (digitalRead(4)==LOW)
                {
                                analogWrite(9,125);
                                delay(100);
                                analogWrite(9,0);
                }
                if (digitalRead(5)==LOW)
                {
                                analogWrite(9,150);
                                delay(100);
                                analogWrite(9,0);
                }
                if (digitalRead(6)==LOW)
                {
                                analogWrite(9,175);
                                delay(100);
                                analogWrite(9,0);
                }
                if (digitalRead(7)==LOW)
                {
                                analogWrite(9,200);
                                delay(100);
                                analogWrite(9,0);
                }
}
