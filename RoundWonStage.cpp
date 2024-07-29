#include "const.h"
#include "RoundWonStage.h"
#include "StagesLocator.h"
#include "SignalsDisplay.h"
#include "GameState.h"
#include "ExpandSequenceLevelUp.h"

void RoundWonStage::playRoundWonAnimation()
{
    signals.green.blink(1500, 1);
}



void RoundWonStage::waitForKey()
{
    Key key(START_KEY);

    while(key.isUp());
}


GameState RoundWonStage::levelUp(GameState gameState)
{
    return ExpandSequenceLevelUp().updateState(gameState);
}

StageInterface *RoundWonStage::run()
{
    playRoundWonAnimation();
    waitForKey();

    return stagesLocator->playRoundStage
        ->setGameState(levelUp(gameState));
}

RoundWonStage *RoundWonStage::setGameState(GameState gameState)
{
    this->gameState = gameState;

    return this;
}
