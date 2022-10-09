/*
closestPowerOfTwoTest.ino

Description
  Test of the RLTools closestPowerOfTwo function. 

Author
  Robert Reay

Revision History
  10-04-2022 : Initial Code
*/

#include "RLArduinoTools.h"

void setup() {
  SerialUSB.begin(9600);
  while(!Serial);
  SerialUSB.println("\nTesting the powerOfTwo function:");
  testByte();
  testInt();
  testLong();
  testSpeed();
  SerialUSB.println("\nTesting complete");
}

void loop() {
}

void testByte()
{
  //Test byte values
  uint8_t lastValue = 0xFF;
  uint8_t value = 0;
  SerialUSB.println("\nTesting Byte");
  //Test each value and print out power of two if changed
  for (uint8_t i = 0; i < 0xFF; i++)
  {
    uint8_t value = closestPowerOfTwo(i);
    if (value != lastValue)
    {
      SerialUSB.print(i);
      SerialUSB.print("\t");
      SerialUSB.println(value);
      lastValue = value;
    }
  } 
}

void testInt()
{
  //Test integer values
  uint16_t lastValue = 0xFFFF;
  uint16_t value = 0;
  SerialUSB.println("\nTesting Int");
  //Test each value and print out power of two if changed
  for (uint16_t i = 0; i < 0xFFFF; i++)
  {
    uint16_t value = closestPowerOfTwo(i);
    if (value != lastValue)
    {
      SerialUSB.print("0x");
      SerialUSB.print(i, HEX);
      SerialUSB.print(" 0x");
      SerialUSB.println(value, HEX);
      lastValue = value;
    }
  }
}

void testLong()
{
  //Test long values
  unsigned long lastValue = 0xFFFFFFFF;
  unsigned long value = 0;
  unsigned long increment = 1;
  unsigned long i = 0;
  SerialUSB.println("\nTesting Long");
  //Test around each power of two to reduce test time
  unsigned long index = 1;
  for (int bitCount = 1; bitCount < 34; bitCount++)
  {
    for (unsigned long i = index - 1; i < index + 3; i++)
    {
      unsigned long value = closestPowerOfTwo(i);
      SerialUSB.print("0x");
      SerialUSB.print(i,HEX);
      SerialUSB.print(" 0x");
      SerialUSB.println(value,HEX);
      lastValue = value;
    }
    index <<= 1;
    SerialUSB.println();
  }
}


void testSpeed()
{
  //Test the function speed
  unsigned long value = 0;
  SerialUSB.println("Testing Speed");
  unsigned long start = micros();
  for (unsigned long i = 0; i < 0xFFFF; i++)
  {
    value = closestPowerOfTwo(i);
  }
  unsigned long end = micros();
  float time = (float)(end - start) / 65536.0;
  SerialUSB.print("Function Speed: ");
  SerialUSB.print(time);
  SerialUSB.println("us");
}
