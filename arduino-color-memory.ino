#include <Arduino.h>
#include "StageInterface.h"
#include "StagesLocator.h"
#include "ServiceLocator.h"

const StagesLocator* stagesLocator = new StagesLocator;
StageInterface* currentStage = stagesLocator->startupStage;

// the setup function runs once when you press reset or power the board
void setup() 
{
  randomSeed(analogRead(A5) * 10);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() 
{
  if (currentStage) {
    currentStage = currentStage->run();
  }
}
