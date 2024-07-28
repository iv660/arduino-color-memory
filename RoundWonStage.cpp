#include "const.h"
#include "RoundWonStage.h"
#include "StagesLocator.h"
#include "SignalsDisplay.h"
#include "GameState.h"

void RoundWonStage::playRoundWonAnimation()
{
    signals.green.blink(1500, 1);
}

void RoundWonStage::playLevelUpAnimation()
{
    signals.all.blink(300, 3);
}

void RoundWonStage::waitForKey()
{
    Key key(START_KEY);

    while(key.isUp());
}

GameState RoundWonStage::levelUp(GameState gameState)
{
    gameState.roundsLeft--;
    
    if (gameState.roundsLeft < 1) {
        gameState.levelOptions.sequenceLength++;
        gameState.roundsLeft = gameState.levelOptions.roundsToPlay;
        playLevelUpAnimation();
        delay(1000);
    }

    return gameState;
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
