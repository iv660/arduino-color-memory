#include "ResetLevelStage.h"
#include "StagesLocator.h"

GameState ResetLevelStage::resetLevel(GameState gameState)
{
    gameState.levelOptions.sequenceLength = 1;
    gameState.levelOptions.maxValue = 2;
    gameState.levelOptions.roundsToPlay = 5;
    gameState.roundsLeft = gameState.levelOptions.roundsToPlay;
    gameState.level = 1;
    gameState.lives = 3;

    stagesLocator->levelUpStage->reset();

    return gameState;
}

/**
 * Runs the ResetLevelStage by resetting the level and returning the next stage to be played.
 *
 * @return Pointer to the next stage to be played
 */
StageInterface *ResetLevelStage::run()
{
    GameState nextGameState = resetLevel(gameState);

    return stagesLocator->confirmRoundStartStage
        ->setGameState(nextGameState);
}

StageInterface* ResetLevelStage::setGameState(GameState gameState)
{
    this->gameState = gameState;
    return this;
}


