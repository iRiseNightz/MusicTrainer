#include <Wire.h>
#include "rgb_lcd.h"
#include <LiquidCrystal_I2C.h>

rgb_lcd lcd;

const int buttonPin = 4;

int buttonState = 0;

int buttonPressed = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0,0);
}

void loop() 
{
  if (buttonState == HIGH) 
  {
    buttonPressed++;
    delay(1000);
  }

  if (buttonPressed = 1)
  {
    lcd.clear();
    lcd.print("Button was Pressed");
    Serial.println("Button was Pressed");
  }
  else
  {
    Serial.println("Button Reset");
    buttonPressed = 0;
  }
  delay(250);
}
