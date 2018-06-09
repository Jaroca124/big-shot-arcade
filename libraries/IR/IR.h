/*
    IR.h - Define an IR distance detector object
    Dylan Santos - 3/13/2018
*/

#ifndef IR_h
#define IR_h

#include "PinMap.h"
#include "Arduino.h"

class IR {
byte state = LOW;
int score;
int sensor;
int LED_Pin;
int islandPin;
unsigned long scoreTime = 0;

public:
    IR(int PinNumber, int setScore, int LED_Pin, int bluePin);
    int checkSensor();
    void island(bool Island);
};

#endif // IR_h
