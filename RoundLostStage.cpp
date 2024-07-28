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

GameState RoundLostStage::resetLevel(GameState gameState)
{
    gameState.levelOptions.sequenceLength = 1;

    return gameState;
}

StageInterface *RoundLostStage::run()
{
    playRoundLostAnimation();
    waitForKey();

    return stagesLocator->playRoundStage
        ->setGameState(
            resetLevel(gameState)
        );
}

RoundLostStage * RoundLostStage::setGameState(GameState gameState)
{
    this->gameState = gameState;
    return this;
}
