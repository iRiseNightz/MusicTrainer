/*macro definitions of Rotary angle sensor and LED pin*/
 
#define ROTARY_ANGLE_SENSOR A0
#define ADC_REF 5 //reference voltage of ADC is 5v.If the Vcc switch on the seeeduino
                    //board switches to 3V3, the ADC_REF should be 3.3
#define GROVE_VCC 5 //VCC of the grove interface is normally 5v
#define FULL_ANGLE 300 //full value of the rotary angle is 300 degrees

#include <Wire.h>
#include "rgb_lcd.h"
#include <LiquidCrystal_I2C.h>

rgb_lcd lcd;

int colorR = 0;
int colorG = 0;
int colorB = 0;
 
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
      colorG = 255;

      lcd.setRGB(colorR, colorG, colorB);
      
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
          delay(500);
          lcd.clear();
          lcd.print("E3 E5 A2 A3");
          lcd.setCursor(0,1);
          lcd.print("A5 D2 D4 D5");
          delay(500);

          firstPlacementX += 3;
          firstPlacementY = 0;
        }
        else
        {
          lcd.setCursor(secondPlacementX, secondPlacementY);
        
          lcd.print("");
          lcd.print("<");
          delay(500);
          lcd.clear();
          lcd.print("E3 E5 A2 A3");
          lcd.setCursor(0,1);
          lcd.print("A5 D2 D4 D5");
          delay(500);

          secondPlacementX += 3;
          secondPlacementY = 1;
        }
      }
      
      colorG = 0;
    }
    else if(degrees >= 101 && degrees <=200)
    {
      colorR = 255;

      lcd.setRGB(colorR, colorG, colorB);
      
      int firstPlacementY = 0;
      int firstPlacementX = 2;

      int secondPlacementY = 1;
      int secondPlacementX = 2;

      int firstLine = 0;
    
      for(int scale = 0; scale <= 7; scale++)
      {
        if(firstLine <= 3)
        {
          firstLine++;
        
          lcd.setCursor(firstPlacementX, firstPlacementY);
        
          lcd.print("");
          lcd.print("<");
          delay(667);
          lcd.clear();
          lcd.print("E3 E5 A2 A3");
          lcd.setCursor(0,1);
          lcd.print("A5 D2 D4 D5");
          delay(667);

          firstPlacementX += 3;
          firstPlacementY = 0;
        }
        else
        {
          lcd.setCursor(secondPlacementX, secondPlacementY);
        
          lcd.print("");
          lcd.print("<");
          delay(667);
          lcd.clear();
          lcd.print("E3 E5 A2 A3");
          lcd.setCursor(0,1);
          lcd.print("A5 D2 D4 D5");
          delay(667);

          secondPlacementX += 3;
          secondPlacementY = 1;
        }
      }
      
      colorR = 0;
    }
    else
    {
      colorB = 255;

      lcd.setRGB(colorR, colorG, colorB);
      
      int firstPlacementY = 0;
      int firstPlacementX = 2;

      int secondPlacementY = 1;
      int secondPlacementX = 2;

      int firstLine = 0;
    
      for(int scale = 0; scale <= 7; scale++)
      {
        if(firstLine <= 3)
        {
          firstLine++;
        
          lcd.setCursor(firstPlacementX, firstPlacementY);
        
          lcd.print("");
          lcd.print("<");
          delay(1000);
          lcd.clear();
          lcd.print("E3 E5 A2 A3");
          lcd.setCursor(0,1);
          lcd.print("A5 D2 D4 D5");
          delay(1000);

          firstPlacementX += 3;
          firstPlacementY = 0;
        }
        else
        {
          lcd.setCursor(secondPlacementX, secondPlacementY);
        
          lcd.print("");
          lcd.print("<");
          delay(1000);
          lcd.clear();
          lcd.print("E3 E5 A2 A3");
          lcd.setCursor(0,1);
          lcd.print("A5 D2 D4 D5");
          delay(1000);

          secondPlacementX += 3;
          secondPlacementY = 1;
        }
      }
      colorB = 0;
    }
    
    delay(250);
}
