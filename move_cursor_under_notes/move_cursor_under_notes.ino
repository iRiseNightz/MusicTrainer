/*
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)

 modified 11/03/21
 by Marc McCabe
 
*/

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 255;
const int colorB = 0;

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

    lcd.setRGB(colorR, colorG, colorB);

    // Print a message to the LCD.
    lcd.print("A B C D E F G");

    delay(1000);
}

void loop() {
    // 
    for (int i = 0; i < 14; i++) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("A B C D E F G");
      lcd.setCursor(i, 1);
        lcd.print("^");
        delay(150);
    }
    
    delay(100);
}
