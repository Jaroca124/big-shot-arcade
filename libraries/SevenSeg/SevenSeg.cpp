/*
*/

#include "Digit.h"
#include "Arduino.h"
#include "SevenSeg.h"
#include "PinMap.h"


SevenSeg::SevenSeg(const int *Test) {

    //const int Digits = sizeof(PinArray)/2;
    //Displays = Digits;
    Serial.println(Test[0]);
    //Serial.println(sizeof(PinArray));
    //Serial.println(Digits);
    //Serial.println(Displays);

    //Digit * DigitArray[Digits];

    //for (int i = 0; i < Digits; i++) {
      //      DigitArray[i] = new Digit(PinArray[i]);
        //    pinMode(PinArray[i], OUTPUT);
   // }
}

SevenSeg::~SevenSeg() {
    for (int i = 0; i < Displays; i++) {
        delete DigitArray[Displays];
    }
}

void SevenSeg::updateValue(int newValue) {
    value = newValue;
}

void SevenSeg::refreshDisplay() {
    for (int i = 0; i < Displays; i++) {
        DigitArray[i] -> updateValue(value/int(pow(10,i)) % 10);
    }
}

