#ifndef PINMAP_H
#define PINMAP_H
const int islandLED_9 = 53;
const int islandLED_8 = 52;
const int islandLED_7 = 51;
const int islandLED_6 = 50;
const int islandLED_5 = 49;
const int islandLED_4 = 48;
const int islandLED_3 = 47;
const int islandLED_2 = 46;
const int islandLED_1 = 45;
const int SelectButton = 44;
const int StartButton = 43;
const int IR_LED_9 = 33;
const int IR_9 = 32;
const int IR_LED_8 = 31;
const int IR_8 = 30;
const int IR_LED_7 = 29;
const int IR_7 = 28;
const int IR_LED_6 = 27;
const int IR_6 = 26;
const int IR_LED_5 = 25;
const int IR_5 = 24;
const int IR_LED_4 = 23;
const int IR_4 = 22;
const int IR_LED_3 = 42;
const int IR_3 = 41;
const int IR_LED_2 = 40;
const int IR_2 = 39;
const int IR_LED_1 = 38;
const int IR_1 = 37;
const int PIN_6 = 36;
const int PIN_5 = 35;
const int PIN_1 = 13;
const int PIN_A = 12;
const int PIN_F = 11;
const int PIN_2 = 10;
const int PIN_3 = 9;
const int PIN_B = 8;
const int PIN_4 = 7;
const int PIN_G = 6;
//const int PIN_DOT = 5;
const int PIN_C = 5;
const int PIN_D = 4;
const int PIN_E = 3;

const int ScorePinArray[] =
{PIN_4, PIN_3, PIN_2, PIN_1};
const int TimePinArray[] =
{PIN_6, PIN_5};
const int SegPinArray[] =
{PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G};
const int IRArray[] =
{IR_1, IR_2, IR_3, IR_4, IR_5,
 IR_6, IR_7, IR_8, IR_9};
const int IR_LEDArray[] =
{IR_LED_1, IR_LED_2, IR_LED_3, IR_LED_4,
 IR_LED_5, IR_LED_6, IR_LED_7, IR_LED_8, IR_LED_9};
const int IslandArray[] =
{islandLED_1, islandLED_2, islandLED_3,
 islandLED_4, islandLED_5, islandLED_6,
 islandLED_7, islandLED_8, islandLED_9};

#endif // PINMAP_H
