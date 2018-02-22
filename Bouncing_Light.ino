int led7 =7;
int led6 =6;
int led5=5;
int led4=4;
void setup() {
  // put your setup code here, to run once:
pinMode (led7, OUTPUT);
pinMode (led6, OUTPUT);
pinMode (led5, OUTPUT);
pinMode (led4, OUTPUT);}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (led7,HIGH);  //the leftmost led will blink first 
delay (1000);  //left led will blink for 1 second
digitalWrite (led7,LOW); // LED7 will turn off
digitalWrite (led6,HIGH);//led6 will blink
delay(1000);
digitalWrite (led5,HIGH);
digitalWrite (led6,LOW);
delay(1000);
digitalWrite (led4,HIGH);
digitalWrite (led5,LOW);
delay(1000);
digitalWrite (led5,HIGH);
digitalWrite (led4,LOW);
delay (1000);
digitalWrite (led6,HIGH);
digitalWrite (led5,LOW);
delay(1000);
digitalWrite (led7,HIGH);
digitalWrite (led6,LOW);}
