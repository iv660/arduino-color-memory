#include "ResetLevelStage.h"
#include "StagesLocator.h"

GameState ResetLevelStage::resetLevel(GameState gameState)
{
    gameState.levelOptions.sequenceLength = 1;
    gameState.levelOptions.maxValue = 2;
    gameState.levelOptions.roundsToPlay = 5;
    gameState.roundsLeft = gameState.levelOptions.roundsToPlay;
    gameState.level = 1;

    stagesLocator->levelUpStage->reset();

    return gameState;
}

StageInterface *ResetLevelStage::run()
{
    GameState nextGameState = resetLevel(gameState);

    return stagesLocator->playRoundStage
        ->setGameState(nextGameState);
}

StageInterface* ResetLevelStage::setGameState(GameState gameState)
{
    this->gameState = gameState;
    return this;
}


