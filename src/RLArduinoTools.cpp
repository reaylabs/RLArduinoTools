/*
RLArduinoTools.cpp

Description
  Collection of helper routines 

Author
  Robert Reay
*/

#include "Arduino.h"
#include "RLArduinoTools.h"

unsigned long RLArduinoTools::closestPowerOfTwo(unsigned long value)
{
  //Return the power of two equal to or greater than the value
  value--;
  value |= value >> 1;
  value |= value >> 2;
  value |= value >> 3;
  value |= value >> 4;
  value |= value >> 5;
  value |= value >> 6;
  value |= value >> 7;
  value |= value >> 8;
  value |= value >> 9;
  value |= value >> 10;
  value |= value >> 11;
  value |= value >> 12;
  value |= value >> 13;
  value |= value >> 14;
  value |= value >> 15;
  value |= value >> 16; 
  value++;
  return value;
};

void RLArduinoTools::startMicrosTimer() {
  // Record the start time
  _startMicrosTime = micros();
};

void RLArduinoTools::startMillisTimer() {
  // Record the start time
  _startMillisTime = millis();
};

unsigned long RLArduinoTools::stopMicrosTimer() {
  unsigned long endTime = micros();
  return (endTime - _startMicrosTime); 
};

unsigned long RLArduinoTools::stopMillisTimer() {
  unsigned long endTime = millis();
  return  (endTime - _startMillisTime);
};