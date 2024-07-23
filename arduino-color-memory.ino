#include <Arduino.h>
#include "StageInterface.h"
#include "BaseStage.h"
#include "StartupStage.h"
#include "PlaySequenceStage.h"
#include "StagesLocator.h"

const StagesLocator* stagesLocator = new StagesLocator();
const StageInterface* currentStage = stagesLocator->startupStage;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (currentStage) {
    currentStage = currentStage->run();
  }
}
