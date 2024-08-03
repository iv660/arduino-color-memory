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
    showLivesLeftTransition(gameState.lives, gameState.lives - 1);
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

void RoundLostStage::showLivesLeftTransition(int from, int to)
{
    dashboard->showLivesLeftTransition(from, to);
    delay(1500);
    dashboard->clear();
}
