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
    lcd.setCursor(0,0);

    lcd.setRGB(colorR, colorG, colorB);
    lcd.print("E3 E5 A2 A3");
    lcd.setCursor(0,1);
    lcd.print("A5 D2 D4 D5");
    delay(1000);

    lcd.setCursor(0,0);
}

void loop() 
{
    int firstPlacementY = 0;
    int firstPlacementX = 2;

    int secondPlacementY = 1;
    int secondPlacementX = 2;

    int firstLine = 0;
    
    for(int scale = 0; scale <= 7; scale++)
    {
      //move cursor to different notes
      if(firstLine <= 3)
      {
        firstLine++;
        
        lcd.setCursor(firstPlacementX, firstPlacementY);
        
        lcd.print("");
        lcd.print("<");
        delay(250);
        lcd.clear();
        lcd.print("E3 E5 A2 A3");
        lcd.setCursor(0,1);
        lcd.print("A5 D2 D4 D5");
        delay(250);

        firstPlacementX += 3;
        firstPlacementY = 0;
      }
      else
      {
        lcd.setCursor(secondPlacementX, secondPlacementY);
        
        lcd.print("");
        lcd.print("<");
        delay(250);
        lcd.clear();
        lcd.print("E3 E5 A2 A3");
        lcd.setCursor(0,1);
        lcd.print("A5 D2 D4 D5");
        delay(250);

        secondPlacementX += 3;
        secondPlacementY = 1;
      }
    }
    
    delay(1000);
}
