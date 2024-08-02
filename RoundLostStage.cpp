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
    waitForKey();

    return stagesLocator->resetLevelStage
        ->setGameState(gameState);
}

RoundLostStage * RoundLostStage::setGameState(GameState gameState)
{
    this->gameState = gameState;
    return this;
}
