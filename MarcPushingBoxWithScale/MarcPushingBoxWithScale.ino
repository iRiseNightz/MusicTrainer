/*
Derived from Yún HTTP Client Sketch
 This example for the Arduino Yún shows how create a basic
 HTTP client that connects to the internet and downloads
 content. In this case, you'll connect to the Arduino
 website and download a version of the logo as ASCII text.
 created by Tom igoe
 May 2013
 This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/HttpClient
 Additions added by Mary Loftus April 2018 
 - adapted from example by Tom DeBell - August 2017 - http://www.open-sensing.org/evaporometerblog/datalog

 modified by Marc McCabe 27/04/21
 */


  /////////////////
 // MODIFY HERE //
/////////////////

// Add your PushingBox Scenario DeviceID here:
  char devid[] = "vE4C2F236BDAD61B";
  
  //////////////
 //   End    //
//////////////

char serverName[] = "api.pushingbox.com";
boolean DEBUG = true;
#include <Bridge.h>
#include <HttpClient.h>

#define ROTARY_ANGLE_SENSOR A0
#define ADC_REF 5
#define GROVE_VCC 5
#define FULL_ANGLE 300

#include <Wire.h>
#include "rgb_lcd.h"
#include <LiquidCrystal_I2C.h>

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 255;
const int colorB = 0;

// button 
const int buttonPin = 4;     // the number of the pushbutton pin
int buttonState = 0;         // pushbutton status

int tempo = 90;


void setup() {
  // Bridge takes about two seconds to start up
  // it can be helpful to use the on-board LED
  // as an indicator for when it has initialized
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  Serial.begin(9600);
  while (!Serial); // wait for a serial connection

   //Rotary sensor setup
    Serial.begin(9600);
    pinMode(ROTARY_ANGLE_SENSOR, INPUT);

    //button setup
    pinMode(buttonPin, INPUT);
    
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setCursor(0,0);

    lcd.setRGB(colorR, colorG, colorB);
    lcd.print("E3 E5 A2 A3");
    lcd.setCursor(0,1);
    lcd.print("A5 D2 D4 D5");

    lcd.setCursor(0,0);
}

void loop() 
{
    int firstPlacementY = 0;
    int firstPlacementX = 2;

    int secondPlacementY = 1;
    int secondPlacementX = 2;

    int firstLine = 0;

    //reset the button state to reenter the while loop
    buttonState = 0;
    lcd.clear();
    delay(1000);
    
    for(int scale = 0; scale <= 7; scale++)
    {
      //move cursor to different notes
      if(firstLine <= 3)
      {
        firstLine++;
        
        lcd.clear();
        lcd.print("E3 E5 A2 A3");
        lcd.setCursor(0,1);
        lcd.print("A5 D2 D4 D5");
        delay(250);
        
        lcd.setCursor(firstPlacementX, firstPlacementY);
        lcd.print("");
        lcd.print("<");
        delay(250);

        firstPlacementX += 3;
        firstPlacementY = 0;
      }
      else
      {
        lcd.clear();
        lcd.print("E3 E5 A2 A3");
        lcd.setCursor(0,1);
        lcd.print("A5 D2 D4 D5");
        delay(250);

        lcd.setCursor(secondPlacementX, secondPlacementY);
        lcd.print("");
        lcd.print("<");
        delay(250);

        secondPlacementX += 3;
        secondPlacementY = 1;
      }
    }

    //marcs amazing addition starts here
    //while loop
    //use int for sentinal value
    //button press changes value 

      //did you succeed text display
      lcd.clear();
      lcd.setRGB(0,0,255);
      lcd.setCursor(0,0);
      lcd.print("Did you succeed?");
      delay(3000);

      
    while(buttonState < 1){
    
    float voltage;
    int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);
    voltage = (float)sensor_value*ADC_REF/1023;
    float degrees = (voltage*FULL_ANGLE)/GROVE_VCC;



    
    //rotary sensor
    if(degrees <=150) // YES
    {
      lcd.clear();
      lcd.setRGB(0,255,0);
      lcd.setCursor(4,0);
      lcd.print("YES / NO");
      lcd.setCursor(5,1);
      lcd.print("^");
      delay(500);

        // read the state of the pushbutton value:
        buttonState = digitalRead(buttonPin);
        
        //choose yes
        if (buttonState == HIGH) 
      {
        lcd.clear();
        lcd.setRGB(0,0,255);
        lcd.setCursor(1,0);
        lcd.print("Good Job.");
        delay(2000);

        // After choosing yes, upload data
        
        // Initialize the client library
        HttpClient client;

        // Make a HTTP request:  
        String APIRequest;
        APIRequest = String(serverName) + "/pushingbox?devid=" + String(devid)+ "&Tempo=" + tempo + "&Outcome=success" ;
        client.get (APIRequest);
        // if there are incoming bytes available
        // from the server, read them and print them:
        while (client.available()) {
          char c = client.read();
      
        }
        Serial.flush();
        String UploadMessage;
        Serial.print("\n Uploaded values");
        delay(5000);
        
      }
    }
    else              // NO
    {
      lcd.clear();
      lcd.setRGB(255,0,0);
      lcd.setCursor(4,0);
      lcd.print("YES / NO");
      lcd.setCursor(10,1);
      lcd.print("^");
      delay(500);

        // read the state of the pushbutton value:
        buttonState = digitalRead(buttonPin);
        //choose no
        if (buttonState == HIGH) 
      {
        lcd.clear();
        lcd.setRGB(0,0,255);
        lcd.setCursor(1,0);
        lcd.print("Try Again.");
        delay(2000);

        // After choosing no, upload data
        
        // Initialize the client library
        HttpClient client;

        // Make a HTTP request:  
        String APIRequest;
        APIRequest = String(serverName) + "/pushingbox?devid=" + String(devid)+ "&Tempo=" + tempo + "&Outcome=fail" ;
        client.get (APIRequest);
        // if there are incoming bytes available
        // from the server, read them and print them:
        while (client.available()) {
          char c = client.read();
      
        }
        Serial.flush();
        String UploadMessage;
        Serial.print("\n Uploaded values");
        delay(5000);
        
        }
      }
    }
    delay(1000);
}

  
