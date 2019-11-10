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

    volatile int pulsewidth_in_0;
    volatile long pulsestart_0;
    volatile int pulsewidth_in_1;
    volatile long pulsestart_1;
    volatile int pulsewidth_in_2;
    volatile long pulsestart_2;
    volatile int pulsewidth_in_3;
    volatile long pulsestart_3;
    volatile int pulsewidth_in_4;
    volatile long pulsestart_4;
    volatile int pulsewidth_in_5;
    volatile long pulsestart_5;
    volatile int pulsewidth_in_6;
    volatile long pulsestart_6;
    volatile int pulsewidth_in_7;
    volatile long pulsestart_7;
    volatile int pulsewidth_in_8;
    volatile long pulsestart_8;
    volatile int pulsewidth_in_9;
    volatile long pulsestart_9;
    volatile int pulsewidth_in_10;
    volatile long pulsestart_10;
    volatile int pulsewidth_in_11;
    volatile long pulsestart_11;
    volatile int pulsewidth_in_12;
    volatile long pulsestart_12;
    volatile int pulsewidth_in_13;
    volatile long pulsestart_13;
    volatile int pulsewidth_in_14;
    volatile long pulsestart_14;
  private:
    byte pin;
    short minVal, midVal, maxVal, tolerance;
    void setInitialInterrupt();
};


extern void isrFalling0();
extern void isrRising0();
extern void isrFalling1();
extern void isrRising1();
extern void isrFalling2();
extern void isrRising2();
extern void isrFalling3();
extern void isrRising3();
extern void isrFalling4();
extern void isrRising4();
extern void isrFalling5();
extern void isrRising5();
extern void isrFalling6();
extern void isrRising6();
extern void isrFalling7();
extern void isrRising7();
extern void isrFalling8();
extern void isrRising8();
extern void isrFalling9();
extern void isrRising9();
extern void isrFalling10();
extern void isrRising10();
extern void isrFalling11();
extern void isrRising11();
extern void isrFalling12();
extern void isrRising12();
extern void isrFalling13();
extern void isrRising13();
extern void isrFalling14();
extern void isrRising14();

#endif
