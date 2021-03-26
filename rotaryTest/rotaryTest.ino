#define ROTARY_ANGLE_SENSOR A0
#define ADC_REF 5
#define GROVE_VCC 5
#define FULL_ANGLE 300

#include <Wire.h>
#include "rgb_lcd.h"
#include <LiquidCrystal_I2C.h>

rgb_lcd lcd;
 
void setup()
{
    Serial.begin(9600);
    pinMode(ROTARY_ANGLE_SENSOR, INPUT);
    lcd.begin(16, 2);
    lcd.setCursor(0,1);
}
 
void loop()
{   
    float voltage;
    int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);
    voltage = (float)sensor_value*ADC_REF/1023;
    float degrees = (voltage*FULL_ANGLE)/GROVE_VCC;

    if(degrees <=100)
    {
      lcd.clear();
      lcd.print("E Major");
    }
    else if(degrees >= 101 && degrees <=200)
    {
      lcd.clear();
      lcd.print("E Minor");
    }
    else
    {
      lcd.clear();
      lcd.print("G Major");
    }
    
    delay(250);
}
