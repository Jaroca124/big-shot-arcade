/*
    Big Shot - Code for the setup and main loop of Dylan and Jake's Big Shot arcade game
    Dylan Santos - 5/25/2018
*/

//CONSTANTS
#include "PinMap.h"
#include "CircusOfValues.h"
#include "pitches.h"

const int Detectors = 9;
const int ScoreArray[Detectors] = {5, 5, 5, 5, 5, 5, 5, 15, 15};

//CLASSES

#include "Digit.h"
#include "SevenSeg.h"
#include "IR.h"

SevenSeg Clock(TimePinArray);
SevenSeg ScoreBoard(ScorePinArray);

//VARIABLES
int timer;
int score = 0;
IR * DetectorArray[Detectors];
unsigned long timerMillis = 0;
unsigned long islandMillis = 0;
int islandCup;
int gameMode = 0;
unsigned long debounce = 0;
//int HighScore[3];

#include <avr/wdt.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Welcome to Big Shot!");
  randomSeed(analogRead(0));
  wdt_reset();
  pinMode(StartButton, INPUT);
  pinMode(SelectButton, INPUT);


  for (int i = 0; i < Detectors; i++) {
    DetectorArray[i] = new IR(IRArray[i], ScoreArray[i], IR_LEDArray[i], IslandArray[i]);
  }

  while (digitalRead(StartButton) == LOW){
    Clock.refreshDisplay();
    ScoreBoard.refreshDisplay();
    if ((digitalRead(SelectButton) == HIGH) && ((millis() - debounce) > 50)) {
      debounce = millis();
      gameMode += 1;
      Clock.updateValue(gameMode + 1);
    }
  }
  timerMillis = millis();



  switch (gameMode%3) {
    
  case 0:
  
  timer = 60;
  islandMillis = millis();
  islandCup = random(8);
  DetectorArray[islandCup] -> island(true);
  
  while (timer > 0) {
    for (int i = 0; i < Detectors; i++) {
      score += DetectorArray[i] -> checkSensor();
    }
    ScoreBoard.updateValue(score);
    if ((millis() - timerMillis) > 1000) {
      timerMillis += 1000;
      timer--;
      Clock.updateValue(timer);
    }
    Clock.refreshDisplay();
    ScoreBoard.refreshDisplay();
    if ((millis() - islandMillis) > 5000) {
      DetectorArray[islandCup] -> island(false);
      islandCup = random(9);
      DetectorArray[islandCup] -> island(true);
      islandMillis += 5000;
    }
  }
  
    
  
  if (digitalRead(StartButton) == HIGH) {     //<====== Make an interrupt
      wdt_enable(WDTO_15MS);
      while(1){}
  }
    break;

  case 1:
    //game2();
    break;

  case 2:
    //game3();
    break;
}


/*      Game 1  
        
        
        
  

  
*/



/*      Game 2



  if (digitalRead(StartButton) == HIGH) {     //<====== Make an interrupt
      wdt_enable(WDTO_15MS);
      while(1){}
  }
*/


/*      Game 3


  if (digitalRead(StartButton) == HIGH) {     //<====== Make an interrupt
      wdt_enable(WDTO_15MS);
      while(1){}
  }
/*



*/
}

void loop() {
  // put your main code here, to run repeatedly:


 
}
