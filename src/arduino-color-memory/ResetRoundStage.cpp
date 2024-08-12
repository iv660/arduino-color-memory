#include "ResetRoundStage.h"
#include "StagesLocator.h"

StageInterface *ResetRoundStage::run()
{
    playResetRoundAnimation();
    GameState updatedGameState = resetRound(gameState);
    
    return stagesLocator->confirmRoundStartStage
        ->setGameState(updatedGameState);
}

StageInterface * ResetRoundStage::setGameState(GameState gameState)
{
    this->gameState = gameState;
    return this;
}

void ResetRoundStage::playResetRoundAnimation()
{
    SignalsDisplay signals;
    signals.all.blink(30, 10);
}

GameState ResetRoundStage::resetRound(GameState gameState)
{
    gameState.roundsLeft = gameState.levelOptions.roundsToPlay;
    return gameState;
}
