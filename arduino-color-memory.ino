#include <Arduino.h>
#include "StageInterface.h"
#include "BaseStage.h"
#include "StartupStage.h"
#include "PlayRoundStage.h"
#include "StagesLocator.h"
#include "SignalsDisplay.h"

const StagesLocator* stagesLocator = new StagesLocator;
StageInterface* currentStage = stagesLocator->startupStage;

// the setup function runs once when you press reset or power the board
void setup() 
{
  // Serial.begin(300);
}

// the loop function runs over and over again forever
void loop() 
{
  SignalsDisplay signals;
  signals.yellow.blink(300, 3);

  if (currentStage) {
    signals.red.blink(300, 3);
    currentStage = currentStage->run();
  }

  signals.white.blink(300, 3);
}
