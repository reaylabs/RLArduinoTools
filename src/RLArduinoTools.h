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

class RLArduinoTools {
  public:
    //constructor
    explicit RLArduinoTools() {};

    //find the closest power of two
    unsigned long closestPowerOfTwo(unsigned long value);

    //execution time functions
    void startMicrosTimer();
    unsigned long stopMicrosTimer();
    void stopMicrosTimerAndPrint();

    void startMillisTimer();
    unsigned long stopMillisTimer();
    void stopMillisTimerAndPrint();

    //Class version
    String version();

  private:
    unsigned long _startMicrosTime;
    unsigned long _startMillisTime;
    const String _version = F("1.1.0");
};

#endif // _RLARDUINOTOOLS_H