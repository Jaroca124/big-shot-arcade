/*
    Digit.cpp - Defines the Digit class for a SevenSeg Display
    Dylan Santos - 3/12/2018
*/

#include "Digit.h"
#include "Arduino.h"
#include "PinMap.h"
#include "CircusOfValues.h"

Digit::Digit(int Pin) {
    pin = Pin;
    pinMode(Pin, OUTPUT);
    state = 0;
}

void Digit::updateValue(int newValue) {
        state = newValue;
        for (int i = 0; i < 7; i++) {
            digitalWrite(SegPinArray[i], CircusOfValues[state][i]);
        }
        digitalWrite(pin, LOW);
        delay(3);
        digitalWrite(pin, HIGH);
}
