
//blocking sensor functions - these will request data and wait until a response is recieved, then return the response

/**
  Returns the value from the requested id
**/

int getSensorData(byte sensorID)
{
  int returnVal;
  byte packetID = 0;
  if (sensorID > 100)
  {
    switch (sensorID)
    {
      case 101:
      case 102:
      case 103:
      case 104:
        packetID = 7;
        break;
      case 105:
      case 106:
      case 107:
      case 108:
        packetID = 14;
        break;
      case 109:
      case 110:
      case 111:
      case 112:
      case 113:
      case 114:
      case 115:
      case 116:
        packetID = 18;
        break;
      case 117:
      case 118:
      case 119:
      case 120:
      case 121:
      case 122:
        packetID = 45;
        break;
    }

  }
  else {
    packetID = sensorID;
  }
  byte MSB = 0;
  byte LSB = 0;
  Roomba.write(142);
  Roomba.write(packetID);
    if(is_in_array(packetID)){
      while (!Roomba.available());
      returnVal = Roomba.read();
    } else {
      while (!Roomba.available());
      MSB = Roomba.read();
      LSB = Roomba.read();
      returnVal = (MSB << 7) | LSB;
    }
    
  return returnVal;
}

//-------------------------------------------------------------------------
bool is_in_array(byte val)
{
  for (int i=0;i<22;i++){
    if (val == single_byte_packets[i])
    {
      return true;
    }
  }
  return false;
}

