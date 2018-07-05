#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);/// REGISTER SELECT PIN,ENABLE PIN,D4 PIN,D5 PIN, D6 PIN, D7 PIN
char ADCSHOW[5];//initializing a character of size 5 for showing the ADC result
void setup()
{
  // set up the LCD's number of columns and rows:
lcd.begin(16, 2);
}
 
void loop()
{
             lcd.print("FluxDensity");//showing name
                lcd.setCursor(0, 1);//move to second line
                lcd.print("(in Gauss):");// showing units
                String ADCVALUE = String((analogRead(A0)-515)/3.76);
 /* Now since the default reference if 5V and resolution is 10bit so for every 5/1024 = 5mV, we get one increment is count, The sensor provides increment voltage of 1.3V for every 1Gauss increment if field.
So we need to divide ADC value by 3.76 for getting the gauss value, now the 0 gauss output of sensor is 2.5V so we need to subtract that first. To hold a 0V read at 0Gauss field. */
                // Convert the reading to a char array
                ADCVALUE.toCharArray(ADCSHOW, 5);
                lcd.print(ADCSHOW);//showing the field strength value
                lcd.print("G   ");
                lcd.setCursor(0, 0);// set the cursor to column 0, line 0
}
