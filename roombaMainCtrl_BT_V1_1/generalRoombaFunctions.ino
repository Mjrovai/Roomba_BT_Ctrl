
// wake up the robot
void wakeUp (void)
{
  setWarningLED(ON);
  digitalWrite(ddPin, HIGH);
  delay(100);
  digitalWrite(ddPin, LOW);
  delay(500);
  digitalWrite(ddPin, HIGH);
  delay(2000);
}

/*--------------------------------------------------------------------------
This command resets the robot, as if you had removed and reinserted the battery. */
void reset(void)
{
  Roomba.write(7);
}

/*--------------------------------------------------------------------------
This command gives you control over Roomba turning on the cliff, wheel-drop and internal charger safety features.*/
void startSafe()
{  
  Roomba.write(128);  //Start
  Roomba.write(131);  //Safe mode
  delay(1000);
}

/*--------------------------------------------------------------------------
This command gives you complete control over Roomba by putting the OI into Full mode, and turning off the cliff, wheel-drop and internal charger safety features.*/
void startFull()
{  
  Roomba.write(128);  //Start
  Roomba.write(132);  //Full mode
  delay(1000);
}

/*--------------------------------------------------------------------------
This command stops the OI. All streams will stop and the robot will no longer respond to commands. Use this command when you are finished working with the robot. */
void stop(void)
{
  Roomba.write(173);
}

/*--------------------------------------------------------------------------
This command powers down Roomba.*/
void powerOff(void)
{
  Roomba.write(133);
}

/*--------------------------------------------------------------------------
This command sends Roomba to seek for its dock.*/
void seekDock(void)
{
  Roomba.write(143);
}

/*-----------------------------------------------------
 This command Play song
 [140] [song #] [lenght] [note#] [note duration]
 [141] [song #]                                      */
void playSound (int num) 
{
  switch (num)
  { 
    case 1: 
      Roomba.write("\x8c\x01\x04\x42\x20\x3e\x20\x42\x20\x3e\x20"); // [140] [1] [4] [68] [32] ... place "start sound" in slot 1
      Roomba.write("\x8d\x01"); // [141] [1] play it (in slot 1)
      break;
 
    case 2: 
      Roomba.write("\x8c\x01\x01\x3c\x20"); // place "low freq sound" in slot 2
      Roomba.write("\x8d\x01"); // play it (in slot 2)
      break;

    case 3:
      Roomba.write("\x8c\x01\x01\x48\x20"); // place "high freq sound" in slot 3
      Roomba.write("\x8d\x01"); // play it (in slot 3)
      break;
  }
}
 

