#include <Arduino.h>
#include "StartupStage.h"
#include "StagesLocator.h"
#include "const.h"
#include "Key.h"
#include "Light.h"

void StartupStage::waitForKeyPress() {

  pinMode(KEY1, INPUT);
  
  while (digitalRead(KEY1) == LOW) {
    shuffleRandomGenerator();
  }

  return;
}

void StartupStage::shuffleRandomGenerator()
{
  random(1, 5);
}

void StartupStage::showHighScore()
{
  dashboard->showHighScore(gameState.highScore);
}

StageInterface* StartupStage::run() 
{
  showHighScore();
  waitForKeyPress();

  return stagesLocator->playRoundStage;
}

