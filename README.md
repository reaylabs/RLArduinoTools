# RLArduinoTools
Collection of Arduino helper routines 

## Functions
```C++
//Return the power of two equal to or greater than the value
unsigned long closestPowerOfTwo(unsigned long value);

//Execution time functions
void startMicrosTimer();
unsigned long stopMicrosTimer();
void startMillisTimer();
unsigned long stopMillisTimer();
```