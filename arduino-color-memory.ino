#include <Arduino.h>
#include "StageInterface.h"
#include "StagesLocator.h"

const StagesLocator* stagesLocator = new StagesLocator;
StageInterface* currentStage = stagesLocator->startupStage;

// the setup function runs once when you press reset or power the board
void setup() 
{
  randomSeed(analogRead(A5));
  // Serial.begin(300);
}

// the loop function runs over and over again forever
void loop() 
{
  if (currentStage) {
    currentStage = currentStage->run();
  }
}
