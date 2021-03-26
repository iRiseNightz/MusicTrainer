#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 255;
const int colorB = 0;
int positionCounter = 15;

void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    lcd.setRGB(colorR, colorG, colorB);
    // Print a message to the LCD.
    delay(1000);
}

void loop() 
{

    for (positionCounter = 7; positionCounter >= -30; positionCounter--)
    {
        // scroll one position left:
        lcd.clear();
        lcd.setCursor(positionCounter, 0);
        //lcd.print("E E3 B B2 G G2 D D2 A A3 E E3");
        lcd.print("E");
        lcd.print(" ");
        lcd.print("E3");
        lcd.print(" ");
        lcd.print("B");
        lcd.print(" ");
        lcd.print("B2");
        lcd.print(" ");
        lcd.print("G");
        lcd.print(" ");
        lcd.print("G2");
        lcd.print(" ");
        lcd.print("D");
        lcd.print(" ");
        lcd.print("D2");
        lcd.print(" ");
        lcd.print("A");
        lcd.print(" ");
        lcd.print("A3");
        lcd.print(" ");
        lcd.print("E");
        lcd.print(" ");
        lcd.print("E3");
        lcd.print(" ");
        
        lcd.setCursor(7,1);
        lcd.print("^");
        // wait a bit:
        delay(150);
    }
    
    //lcd.clear();
    // delay at the end of the full loop:
    //delay(1000);
}
