#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int Htime;              //integer for storing high time
int Ltime;                //integer for storing low time
float Ttime;            // integer for storing total time of a cycle
float frequency;        //storing frequency
void setup()
{
    pinMode(8,INPUT);
    lcd.begin(16, 2);
}
void loop()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Frequency of signal");
    Htime=pulseIn(8,HIGH);      //read high time
    Ltime=pulseIn(8,LOW);        //read low time
    
    Ttime = Htime+Ltime;
    frequency=1000000/Ttime;    //getting frequency with Ttime is in Micro seconds
    lcd.setCursor(0,1);
    lcd.print(frequency);
    lcd.print(" Hz");
    delay(500);
}
