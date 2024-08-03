#include "const.h"
#include "RoundLostStage.h"
#include "StagesLocator.h"
#include "SignalsDisplay.h"
#include "GameState.h"

void RoundLostStage::playRoundLostAnimation()
{
    SignalsDisplay signals;
    signals.red.blink(1500, 1);
}

void RoundLostStage::waitForKey()
{
    Key key(START_KEY);

    while(key.isUp());
}

StageInterface *RoundLostStage::run()
{
    playRoundLostAnimation();
    dropLife();

    return getNextStage();
}

StageInterface *RoundLostStage::getNextStage()
{
    if (hasLivesLeft()) {
        return stagesLocator->resetRoundStage
            ->setGameState(gameState);
    } else {
        return stagesLocator->resetLevelStage
            ->setGameState(gameState);
    }
}

bool RoundLostStage::hasLivesLeft()
{
    return gameState.lives > 0;
}

void RoundLostStage::dropLife()
{
    gameState.lives--;
}

RoundLostStage * RoundLostStage::setGameState(GameState gameState)
{
    this->gameState = gameState;
    return this;
}
