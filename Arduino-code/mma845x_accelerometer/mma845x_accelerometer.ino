#include <Wire.h>
#include "Adafruit_MMA8451.h"

// Make sure Adafruit_MMA8451.h:26 has correct I2C Address. If pin SA0 is grounded, this address should be 0x1C. Otherwise, 0x1D.
// Make sure Adafruit_MMA8451.cpp:112 has correct deviceid. I need to use 0x2A. See :114 where deviceid is returned.

// See datasheet https://www.nxp.com/docs/en/data-sheet/MMA8451Q.pdf
// And https://learn.adafruit.com/adafruit-mma8451-accelerometer-breakout

unsigned long timer = 0;
long loopTime = 1250;   // microseconds // Need to go over this, 12.5 ms is only 80 Hz, but data seems to come faster

Adafruit_MMA8451 mma = Adafruit_MMA8451();

uint8_t addr = 0x1C; // Set correct I2C address here. Normally 0x1C or 0x1D.

void setup() {
  Serial.begin(115200);
  Serial.println("Starting");
  timer = micros();
  if (! mma.begin(addr)) {
    while (1);
  }
    mma.setRange(MMA8451_RANGE_2_G);
    mma.setDataRate(MMA8451_DATARATE_800_HZ);
}
 
void loop() {
  timeSync(loopTime);
  mma.read();
  Serial.println(mma.z);
}
 
void timeSync(unsigned long deltaT)
{
  unsigned long currTime = micros();
  long timeToDelay = deltaT - (currTime - timer);
  if (timeToDelay > 5000)
  {
    delay(timeToDelay / 1000);
    delayMicroseconds(timeToDelay % 1000);
  }
  else if (timeToDelay > 0)
  {
    delayMicroseconds(timeToDelay);
  }
  else
  {
      // timeToDelay is negative so we start immediately
  }
  timer = currTime + timeToDelay;
}
