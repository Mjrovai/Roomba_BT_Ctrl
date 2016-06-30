/*------------------------------------------------------------------
  Roomba Control via BT/Android
  ==> Main commands according IRobot Open Interface doc:  http://www.irobotweb.com/~/media/MainSite/PDFs/About/STEM/Create/iRobot_Roomba_600_Open_Interface_Spec.pdf?la=enBasic 
  ==> Using Android app: https://play.google.com/store/apps/details?id=appinventor.ai_mjrovai.MJRoBot_II_BT_Command_V2&hl=en
  ==> Several commands based on Create2 library developed by Dom Amato: https://github.com/brinnLabs/Create2
  Marcelo Jose Rovai - 30 June, 2016 - Visit: http://mjrobot.org
-------------------------------------------------------------------*/

#include "roombaDefines.h"
#include <SoftwareSerial.h>

// Roomba Create2 connection
int rxPin=10;
int txPin=11;
SoftwareSerial Roomba(rxPin,txPin);

// BT Module (HC-06)
SoftwareSerial BT1(8, 9); // El pin 8 es Rx y el pin 9 es Tx

//---------------------------------------------
void setup() 
{
  Roomba.begin(19200);
  BT1.begin(19200);
  Serial.begin(19200);
  
  pinMode(ddPin, OUTPUT);
  pinMode(ledPin, OUTPUT); //spare if needed for test purpose
  pinMode(buttonPin, INPUT_PULLUP); //used for "start" for test purposes

  delay(2000);
  Serial.print("Roomba Remote Control");
  BT1.print("Roomba Remote Control");
  BT1.println('\n');
  
  wakeUp ();   // Wake-up Roomba
  startSafe(); // Start Roomba in Safe Mode

  // turn-off all LEDs and Display
  setPowerLED(128,0);
  setDebrisLED(OFF);
  setDockLED(OFF);
  setSpotLED(OFF);
  setWarningLED(OFF);
  cleanDigitLED ();

  playSound (1); // start sound
  while (digitalRead(buttonPin))
  {  
    setDebrisLED(ON);
    writeLEDs ('-', '-', '-', '-');
  }
  setDebrisLED(OFF);
  writeLEDs ('s', 't', 'o', 'p');
  
   playSound (2);

  //motorSquareTest(); // un-comment if you want to test Roomba doing a square 
  //turnCW (40, 180);  //un-comment if you want to test Roomba spin clock-wise 180 degrees and stop
  //driveWheels(20, -20); //un-comment if you want to test Roomba spin
  //driveLeft(20); //un-comment if you want to test Roomba turning left 

}

void loop() 
{
   checkBTcmd();  // verify if a comand is received from BT remote control
   manualCmd ();
}

