#include <Arduino.h>
#include "StartupStage.h"
#include "StagesLocator.h"
#include "const.h"
#include "Key.h"
#include "Light.h"
#include "SignalsDisplay.h"

void StartupStage::waitForKeyPress() {

  pinMode(KEY1, INPUT);
  
  while (digitalRead(KEY1) == LOW);

  return;
}

StageInterface* StartupStage::run() 
{
  SignalsDisplay signals;
  signals.blue.blink(300, 3);

  waitForKeyPress();

  signals.green.blink(300, 3);

  return stagesLocator->startupStage;
  // StagesLocator localStagesLocator; 
  // return localStagesLocator.startupStage;
  // return stagesLocator->experimentStage;
}

