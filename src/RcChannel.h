/*
Author: Ahmad Shahril
Date: 26/02/2018
Description: This library is made for using RC receiver with Arduino.
*/

#ifndef RcChannel_H_INCLUDED
#define RcChannel_H_INCLUDED

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <EnableInterrupt.h>

class RcChannel {
  public:
    RcChannel(byte pin, short minVal = 1100, short midVal = 1500, short maxVal = 1900);
    void calibrate();
    void calibrate(unsigned long duration);
    short readRaw();
    short readPercentage();
    void setTolerance(short toleranceVal);
	void setMinVal(short minValue);
	void setMidVal(short midValue);
	void setMaxVal(short maxValue);
	short getToleranceVal();
	short getMinVal();
	short getMidVal();
	short getMaxVal();

  private:
    byte pin;
    short minVal, midVal, maxVal, tolerance;
    void isrRising();
    void isrFalling();
};

#endif
