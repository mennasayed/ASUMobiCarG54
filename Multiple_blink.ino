int led = 13;
int led2 = 12;
int led3 = 11;


void setup() {               
  
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT); 
}


void loop() {
  digitalWrite(led, HIGH);   
  delay(100);               
  digitalWrite(led, LOW);    
  delay(100); 
  {digitalWrite(led2, HIGH);
delay(100);
digitalWrite(led2, LOW);
delay(100);}
{digitalWrite(led3, HIGH);
delay(100);
digitalWrite(led3, LOW);
delay(100);}// wait for a second
}
