#include <Wire.h>
#include "rgb_lcd.h"
#include <LiquidCrystal_I2C.h>

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 255;
const int colorB = 0;

void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setCursor(7,0);

    lcd.setRGB(colorR, colorG, colorB);
    // Print a message to the LCD.
    lcd.print("E E3 B B2 G G2 D D2 A A3 E E3");
    delay(1000);
}

void loop() 
{
    lcd.setCursor(7,1);
    lcd.print("^"); 
    lcd.setCursor(7,0);

    // scroll 13 positions (string length) to the left
    // to move it offscreen left:
    for (int positionCounter = 0; positionCounter < 13; positionCounter++) 
    {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        lcd.setCursor(7,1);
        lcd.print("^");
        // wait a bit:
        delay(150);
    }
    lcd.setCursor(7,1);
        lcd.print("^");

    // delay at the end of the full loop:
    delay(1000);
}
