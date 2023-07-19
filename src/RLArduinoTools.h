/*
RLArduinosTools.h

Description
  Collection of helper routines 

Author
  Robert Reay
*/

#ifndef _RLARDUINOTOOLS_H_
#define _RLARDUINOTOOLS_H_

#include "Arduino.h"

#define LIB_VERSION  (F("1.0.0"))

class RLArduinoTools {
  public:
    explicit RLArduinoTools() {};
    unsigned long closestPowerOfTwo(unsigned long value);
    void startMicrosTimer();
    unsigned long stopMicrosTimer();
    void startMillisTimer();
    unsigned long stopMillisTimer();
  private:
    unsigned long _startMicrosTime;
    unsigned long _startMillisTime;
};

#endif // _RLARDUINOTOOLS_H