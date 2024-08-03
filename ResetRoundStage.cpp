#include "ResetRoundStage.h"
#include "StagesLocator.h"

StageInterface *ResetRoundStage::run()
{
    playResetRoundAnimation();
    return stagesLocator->resetLevelStage;
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
