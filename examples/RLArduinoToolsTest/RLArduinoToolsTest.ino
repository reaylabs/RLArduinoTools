/*
RLArduinoToolsTest.ino

Description
  Test of the RLTools closestPowerOfTwo function. 

Author
  Robert Reay
*/

#include "RLArduinoTools.h"

//Create the tool object
RLArduinoTools t;

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("\nTesting the powerOfTwo function:");
  testByte();
  testInt();
  testLong();
  testMillisSpeed();
  testMicrosSpeed();
  Serial.println("\nTesting complete");
}

void loop() {
}

void testByte()
{
  //Test byte values
  uint8_t lastValue = 0xFF;
  uint8_t value = 0;
  Serial.println("\nTesting Byte");
  //Test each value and print out power of two if changed
  for (uint8_t i = 0; i < 0xFF; i++)
  {
    uint8_t value = t.closestPowerOfTwo(i);
    if (value != lastValue)
    {
      Serial.print(i);
      Serial.print("\t");
      Serial.println(value);
      lastValue = value;
    }
  } 
}

void testInt()
{
  //Test integer values
  uint16_t lastValue = 0xFFFF;
  uint16_t value = 0;
  Serial.println("\nTesting Int");
  //Test each value and print out power of two if changed
  for (uint16_t i = 0; i < 0xFFFF; i++)
  {
    uint16_t value = t.closestPowerOfTwo(i);
    if (value != lastValue)
    {
      Serial.print("0x");
      Serial.print(i, HEX);
      Serial.print(" 0x");
      Serial.println(value, HEX);
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
  Serial.println("\nTesting Long");
  //Test around each power of two to reduce test time
  unsigned long index = 1;
  for (int bitCount = 1; bitCount < 34; bitCount++)
  {
    for (unsigned long i = index - 1; i < index + 3; i++)
    {
      unsigned long value = t.closestPowerOfTwo(i);
      Serial.print("0x");
      Serial.print(i,HEX);
      Serial.print(" 0x");
      Serial.println(value,HEX);
      lastValue = value;
    }
    index <<= 1;
    Serial.println();
  }
}


void testMillisSpeed()
{
  //Test the function speed
  unsigned long value = 0;
  Serial.println("Testing Millis Speed");
  t.startMillisTimer();
  for (unsigned long i = 0; i < 0xFFFF; i++)
  {
    value = t.closestPowerOfTwo(i);
  }
  unsigned long time = t.stopMillisTimer();
  Serial.print("Function Speed: ");
  Serial.print(time);
  Serial.println("ms");
}

void testMicrosSpeed() {
  Serial.println("Testing Micros Speed");
  t.startMicrosTimer();
  delayMicroseconds(100);
  unsigned long time = t.stopMicrosTimer();
    Serial.print("Function Speed: ");
  Serial.print(time);
  Serial.println("us");
}
