#ifndef SevenSeg_h
#define SevenSeg_h

#include "Digit.h"
#include "Arduino.h"

class SevenSeg {
    int Displays;
//    int Pins[];
    int value = 0;
    Digit * DigitArray[];

public:
    SevenSeg(const int *PinArray);
    ~SevenSeg();
    void updateValue(int newValue);
    void refreshDisplay();
};

#endif // SevenSeg_h
