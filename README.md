# RLArduinoTools
Collection of Arduino helper routines 

## Functions
```C++
    //Find the power of two equal to or greater than the value
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
```