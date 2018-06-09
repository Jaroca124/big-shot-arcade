/*
    Digit.h - Library for a single Seven Segment display digit
    Dylan Santos - 3/12/2018
*/

#ifndef Digit_h
#define Digit_h

#include "Arduino.h"

class Digit {
        int state;
        int pin;
    public:
        Digit(int Pin);
        void updateValue(int newValue);
};


#endif // Digit_h
