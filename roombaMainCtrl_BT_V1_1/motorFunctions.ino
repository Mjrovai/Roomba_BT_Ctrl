void drive(int velocity, int radius)
{
  clamp(velocity, -500, 500); //def max and min velocity in mm/s
  clamp(radius, -2000, 2000); //def max and min radius in mm
  
  Roomba.write(137);
  Roomba.write(velocity >> 8);
  Roomba.write(velocity);
  Roomba.write(radius >> 8);
  Roomba.write(radius);
}

//---------------------------------------------------------------

void driveWheels(int right, int left)
{
  clamp(right, -500, 500);
  clamp(left, -500, 500);
  
  Roomba.write(145);
  Roomba.write(right >> 8);
  Roomba.write(right);
  Roomba.write(left >> 8);
  Roomba.write(left);
  }

//---------------------------------------------------------------
void driveWheelsPWM(int rightPWM, int leftPWM)
{
  clamp(rightPWM, -255, 255);
  clamp(leftPWM, -255, 255);
  
  Roomba.write(146);
  Roomba.write(rightPWM >> 8);
  Roomba.write(rightPWM);
  Roomba.write(leftPWM >> 8);
  Roomba.write(leftPWM);
}

//---------------------------------------------------------------
void turnCW(unsigned short velocity, unsigned short degrees)
{
  drive(velocity, -1);
  clamp(velocity, 0, 500);
  delay(6600);
  //delay((1580 + 2.25*velocity)/velocity*degrees);
  //delay((-0.03159720835 * velocity + 21.215270835) * degrees);
  drive(0,0);
}

//---------------------------------------------------------------
void turnCCW(unsigned short velocity, unsigned short degrees)
{
  drive(velocity, 1); 
  clamp(velocity, 0, 500);
  delay(6600);
  //delay(2708.3333/velocity*degrees);
  //delay((1580 + 2.25*velocity)/velocity*degrees);
  //delay((-0.03159720835 * velocity + 21.215270835) * degrees);
  drive(0,0);
}

//---------------------------------------------------------------
void driveStop(void)
{
  drive(0,0);
}

//---------------------------------------------------------------
void driveLeft(int left)
{
  driveWheels(left, 0);
}

//---------------------------------------------------------------
void driveRight(int right)
{
  driveWheels(0, right);
}


//---------------------------------------------------------------
void motorSquareTest(void)
{  
  setPowerLED(0,128);
  drive (60, 0);
  delay(5000);
  driveStop();
  turnCCW (30, 90);
  
  setPowerLED(64,128);
  drive (60, 0);
  delay(5000);
  driveStop();
  turnCCW (30, 90);
  
  setPowerLED(128,128);
  drive (60, 0);
  delay(5000);
  driveStop();
  turnCCW (30, 90);

  setPowerLED(190,128);
  drive (60, 0);
  delay(5000);
  driveStop();
  setPowerLED(255,128);
  turnCCW (30, 90);
  setPowerLED(0,0);
}
