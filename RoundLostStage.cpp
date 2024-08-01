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
    gameState.levelOptions.maxValue = 2;
    gameState.levelOptions.roundsToPlay = 5;
    gameState.roundsLeft = gameState.levelOptions.roundsToPlay;
    gameState.level = 1;

    stagesLocator->levelUpStage->reset();

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
