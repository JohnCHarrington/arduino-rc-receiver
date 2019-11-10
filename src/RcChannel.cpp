/*
Author: Ahmad Shahril
Date: 26/02/2018
Description: This library is made for using RC receiver with Arduino.
*/

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <EnableInterrupt.h>
#include "RcChannel.h"

RcChannel::RcChannel(byte pin, short minVal, short midVal, short maxVal):
	pin(pin), minVal(minVal), midVal(midVal), maxVal(maxVal) {
		pinMode(pin, INPUT);
                setInitialInterrupt();
		tolerance = 50;
}

void RcChannel::calibrate() {
	short reading = readRaw();

	if(reading < minVal) {
		minVal = reading;
	}

	if(reading > maxVal) {
		maxVal = reading;
	}

	midVal = ((maxVal - minVal) / 2) + minVal;
}

void RcChannel::calibrate(unsigned long duration) {
	unsigned long calibrateStart = millis();

	while (millis() - calibrateStart < duration) {
		calibrate();
	}
}

short RcChannel::readRaw() {
  switch (pin) {
    case 0: {return pulsewidth_in_0;}
    case 1: {return pulsewidth_in_1;}
    case 2: {return pulsewidth_in_2;}
    case 3: {return pulsewidth_in_3;}
    case 4: {return pulsewidth_in_4;}
    case 5: {return pulsewidth_in_5;}
    case 6: {return pulsewidth_in_6;}
    case 7: {return pulsewidth_in_7;}
    case 8: {return pulsewidth_in_8;}
    case 9: {return pulsewidth_in_9;}
    case 10: {return pulsewidth_in_10;}
    case 11: {return pulsewidth_in_11;}
    case 12: {return pulsewidth_in_12;}
    case 13: {return pulsewidth_in_13;}
    case 14: {return pulsewidth_in_14;}
  }
}

short RcChannel::readPercentage() {
	short reading = constrain(readRaw(), minVal, maxVal);

	if(reading <= midVal + tolerance && reading >= midVal - tolerance) {
		return 0;
	}
	else {
		return map(reading, minVal, maxVal, -100, 100);
	}
}

void RcChannel::setTolerance(short toleranceVal){
	tolerance = toleranceVal;
}

void RcChannel::setMinVal(short val) {
	minVal = val;
}

void RcChannel::setMidVal(short val) {
	midVal = val;
}

void RcChannel::setMaxVal(short val) {
	maxVal = val;
}

short RcChannel::getToleranceVal() {
	return tolerance;
}

short RcChannel::getMinVal() {
	return minVal;
}

short RcChannel::getMidVal() {
	return midVal;
}

short RcChannel::getMaxVal() {
	return maxVal;
}

void RcChannel::setInitialInterrupt() {
  switch (pin) {
    case 0: {enableInterrupt(0, isrRising0, RISING);}
    case 1: {enableInterrupt(1, isrRising1, RISING);}
    case 2: {enableInterrupt(2, isrRising2, RISING);}
    case 3: {enableInterrupt(3, isrRising3, RISING);}
    case 4: {enableInterrupt(4, isrRising4, RISING);}
    case 5: {enableInterrupt(5, isrRising5, RISING);}
    case 6: {enableInterrupt(6, isrRising6, RISING);}
    case 7: {enableInterrupt(7, isrRising7, RISING);}
    case 8: {enableInterrupt(8, isrRising8, RISING);}
    case 9: {enableInterrupt(9, isrRising9, RISING);}
    case 10: {enableInterrupt(10, isrRising10, RISING);}
    case 11: {enableInterrupt(11, isrRising11, RISING);}
    case 12: {enableInterrupt(12, isrRising12, RISING);}
    case 13: {enableInterrupt(13, isrRising13, RISING);}
    case 14: {enableInterrupt(14, isrRising14, RISING);}
  }
}

// ISR FUNCTIONS FOR ALL PINS
static volatile int pulsewidth_in_0 = -100;
static volatile long pulse_start_0;
static volatile int pulsewidth_in_1 = -100;
static volatile long pulse_start_1;
static volatile int pulsewidth_in_2 = -100;
static volatile long pulse_start_2;
static volatile int pulsewidth_in_3 = -100;
static volatile long pulse_start_3;
static volatile int pulsewidth_in_4 = -100;
static volatile long pulse_start_4;
static volatile int pulsewidth_in_5 = -100;
static volatile long pulse_start_5;
static volatile int pulsewidth_in_6 = -100;
static volatile long pulse_start_6;
static volatile int pulsewidth_in_7 = -100;
static volatile long pulse_start_7;
static volatile int pulsewidth_in_8 = -100;
static volatile long pulse_start_8;
static volatile int pulsewidth_in_9 = -100;
static volatile long pulse_start_9;
static volatile int pulsewidth_in_10 = -100;
static volatile long pulse_start_10;
static volatile int pulsewidth_in_11 = -100;
static volatile long pulse_start_11;
static volatile int pulsewidth_in_12 = -100;
static volatile long pulse_start_12;
static volatile int pulsewidth_in_13 = -100;
static volatile long pulse_start_13;
static volatile int pulsewidth_in_14 = -100;
static volatile long pulse_start_14;


extern void isrRising0() {
  pulse_start_0 = micros();
  disableInterrupt(0);
  enableInterrupt(0, isrFalling0, FALLING);
}

extern void isrFalling0() {
  pulsewidth_in_0 = micros() - pulse_start_0;
  disableInterrupt(0);
  enableInterrupt(0, isrRising0, RISING);
}
extern void isrRising1() {
  pulse_start_1 = micros();
  disableInterrupt(1);
  enableInterrupt(1, isrFalling1, FALLING);
}

extern void isrFalling1() {
  pulsewidth_in_1 = micros() - pulse_start_1;
  disableInterrupt(1);
  enableInterrupt(1, isrRising1, RISING);
}
extern void isrRising2() {
  pulse_start_2 = micros();
  disableInterrupt(2);
  enableInterrupt(2, isrFalling2, FALLING);
}

extern void isrFalling2() {
  pulsewidth_in_2 = micros() - pulse_start_2;
  disableInterrupt(2);
  enableInterrupt(2, isrRising2, RISING);
}
extern void isrRising3() {
  pulse_start_3 = micros();
  disableInterrupt(3);
  enableInterrupt(3, isrFalling3, FALLING);
}

extern void isrFalling3() {
  pulsewidth_in_3 = micros() - pulse_start_3;
  disableInterrupt(3);
  enableInterrupt(3, isrRising3, RISING);
}
extern void isrRising4() {
  pulse_start_4 = micros();
  disableInterrupt(4);
  enableInterrupt(4, isrFalling4, FALLING);
}

extern void isrFalling4() {
  pulsewidth_in_4 = micros() - pulse_start_4;
  disableInterrupt(4);
  enableInterrupt(4, isrRising4, RISING);
}
extern void isrRising5() {
  pulse_start_5 = micros();
  disableInterrupt(5);
  enableInterrupt(5, isrFalling5, FALLING);
}

extern void isrFalling5() {
  pulsewidth_in_5 = micros() - pulse_start_5;
  disableInterrupt(5);
  enableInterrupt(5, isrRising5, RISING);
}
extern void isrRising6() {
  pulse_start_6 = micros();
  disableInterrupt(6);
  enableInterrupt(6, isrFalling6, FALLING);
}

extern void isrFalling6() {
  pulsewidth_in_6 = micros() - pulse_start_6;
  disableInterrupt(6);
  enableInterrupt(6, isrRising6, RISING);
}
extern void isrRising7() {
  pulse_start_7 = micros();
  disableInterrupt(7);
  enableInterrupt(7, isrFalling7, FALLING);
}

extern void isrFalling7() {
  pulsewidth_in_7 = micros() - pulse_start_7;
  disableInterrupt(7);
  enableInterrupt(7, isrRising7, RISING);
}
extern void isrRising8() {
  pulse_start_8 = micros();
  disableInterrupt(8);
  enableInterrupt(8, isrFalling8, FALLING);
}

extern void isrFalling8() {
  pulsewidth_in_8 = micros() - pulse_start_8;
  disableInterrupt(8);
  enableInterrupt(8, isrRising8, RISING);
}
extern void isrRising9() {
  pulse_start_9 = micros();
  disableInterrupt(9);
  enableInterrupt(9, isrFalling9, FALLING);
}

extern void isrFalling9() {
  pulsewidth_in_9 = micros() - pulse_start_9;
  disableInterrupt(9);
  enableInterrupt(9, isrRising9, RISING);
}
extern void isrRising10() {
  pulse_start_10 = micros();
  disableInterrupt(10);
  enableInterrupt(10, isrFalling10, FALLING);
}

extern void isrFalling10() {
  pulsewidth_in_10 = micros() - pulse_start_10;
  disableInterrupt(10);
  enableInterrupt(10, isrRising10, RISING);
}
extern void isrRising11() {
  pulse_start_11 = micros();
  disableInterrupt(11);
  enableInterrupt(11, isrFalling11, FALLING);
}

extern void isrFalling11() {
  pulsewidth_in_11 = micros() - pulse_start_11;
  disableInterrupt(11);
  enableInterrupt(11, isrRising11, RISING);
}
extern void isrRising12() {
  pulse_start_12 = micros();
  disableInterrupt(12);
  enableInterrupt(12, isrFalling12, FALLING);
}

extern void isrFalling12() {
  pulsewidth_in_12 = micros() - pulse_start_12;
  disableInterrupt(12);
  enableInterrupt(12, isrRising12, RISING);
}
extern void isrRising13() {
  pulse_start_13 = micros();
  disableInterrupt(13);
  enableInterrupt(13, isrFalling13, FALLING);
}

extern void isrFalling13() {
  pulsewidth_in_13 = micros() - pulse_start_13;
  disableInterrupt(13);
  enableInterrupt(13, isrRising13, RISING);
}
extern void isrRising14() {
  pulse_start_14 = micros();
  disableInterrupt(14);
  enableInterrupt(14, isrFalling14, FALLING);
}

extern void isrFalling14() {
  pulsewidth_in_14 = micros() - pulse_start_14;
  disableInterrupt(14);
  enableInterrupt(14, isrRising14, RISING);
}
