#include <Arduino.h>
#include "StartupStage.h"
#include "StagesLocator.h"
#include "const.h"
#include "Key.h"
#include "Light.h"

void StartupStage::waitForKeyPress() {

  pinMode(KEY1, INPUT);
  
  while (digitalRead(KEY1) == LOW);

  return;
}

StageInterface* StartupStage::run() 
{
  waitForKeyPress();

  return stagesLocator->playRoundStage;
}

