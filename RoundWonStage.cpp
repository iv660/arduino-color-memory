#include "const.h"
#include "RoundWonStage.h"
#include "StagesLocator.h"
#include "SignalsDisplay.h"
#include "GameState.h"
#include "ExtendSequenceLevelUp.h"

void RoundWonStage::playRoundWonAnimation()
{
    signals.green.blink(1500, 1);
}

void RoundWonStage::waitForKey()
{
    Key key(START_KEY);

    while(key.isUp());
}

bool RoundWonStage::isReadyForNextLevel()
{
    return gameState.roundsLeft < 1;
}

StageInterface *RoundWonStage::getNextStage()
{
    if (isReadyForNextLevel()) {
        return stagesLocator->levelUpStage
            ->setGameState(gameState);
    }

    return stagesLocator->playRoundStage
        ->setGameState(gameState);
}

void RoundWonStage::nextRound()
{
    gameState.roundsLeft--;
}

StageInterface *RoundWonStage::run()
{
    nextRound();
    playRoundWonAnimation();
    waitForKey();

    return getNextStage();
}

RoundWonStage *RoundWonStage::setGameState(GameState gameState)
{
    this->gameState = gameState;

    return this;
}