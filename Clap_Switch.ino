const int analogInPin = A0;  // Analog input pin 0
int sensorValue = 0;   
void setup() 
{
 DDRD = 0xFF;
}
void loop() 
{
 sensorValue = analogRead(analogInPin);    //read ADC value on channel 0
 if(sensorValue>60)
 {
  PORTD ^=(1<<7); //If there is a peak toggle the LED on and OFF on pin7.
  delay(250);
  }
}
