/*
    IR.cpp - Define an IR distance detector object
    Dylan Santos - 5/26/2018
*/

#include "IR.h"
#include "PinMap.h"
#include "Arduino.h"


IR::IR(int PinNumber, int setScore, int LED, int bluePin) {
    sensor = PinNumber;
    pinMode(sensor, INPUT);
    score = setScore;
    LED_Pin = LED;
    pinMode(LED_Pin, OUTPUT);
    islandPin = bluePin;
    pinMode(islandPin, OUTPUT);
}

int IR::checkSensor() {
    if ((millis() - scoreTime) > 300) {
        digitalWrite(LED_Pin, LOW);
    }
    if ((millis() - scoreTime) < 50) {
        return 0;
    }
    if ((digitalRead(sensor) == LOW) && (state == HIGH)) {
        state = LOW;
        digitalWrite(LED_Pin, HIGH);
        scoreTime = millis();
        return score;
    }
    else {
        state = digitalRead(sensor);
        return 0;
    }
}

void IR::island(bool Island) {
    if (Island){
        digitalWrite(islandPin, HIGH);
        score *= 3;
        }
    else {
        digitalWrite(islandPin, LOW);
        score /= 3;
    }
}

