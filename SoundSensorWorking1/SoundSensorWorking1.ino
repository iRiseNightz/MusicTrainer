#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 255;

void setup() 
{
    Serial.begin(9600);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    lcd.setRGB(colorR, colorG, colorB);

    // Print a message to the LCD.
    lcd.print("Audio Levels");

    delay(1000);
}

void loop() 
{
      // set the cursor to column 0, line 1
      // (note: line 1 is the second row, since counting begins with 0):
      lcd.setCursor(0, 1);
      // print the number of seconds since reset:
      //lcd.print(millis() / 1000);
      int sensorValue = analogRead(A0);
      // print out the value you read:
      if(sensorValue >=400)
      {
        Serial.println(sensorValue);
        lcd.print(sensorValue);
        delay(100);
      }
}
