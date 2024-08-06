#include <Arduino.h>
#include "StartupStage.h"
#include "StagesLocator.h"
#include "const.h"
#include "Key.h"
#include "Light.h"
#include "storage/Storage.cpp"

void StartupStage::waitForKeyPress()
{
    pinMode(KEY1, INPUT);

    while (digitalRead(KEY1) == LOW)
    {
        shuffleRandomGenerator();
    }

    return;
}

void StartupStage::shuffleRandomGenerator()
{
    random(1, 5);
}

void StartupStage::initGameState()
{
    GameState clearGameState;
    gameState = clearGameState;

    PersistentData data = getPersistentData();

    gameState.highScore = data.highScore;
}

PersistentData StartupStage::getPersistentData()
{
    return Storage().getData();
}

void StartupStage::showHighScore()
{
    dashboard->showHighScore(gameState.highScore);
}

StageInterface *StartupStage::run()
{
    initGameState();
    showHighScore();
    waitForKeyPress();

    return stagesLocator->playRoundStage->setGameState(gameState);
}
