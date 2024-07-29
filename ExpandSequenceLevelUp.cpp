#include <Arduino.h>
#include "ExpandSequenceLevelUp.h"
#include "SignalsDisplay.h"


GameState ExpandSequenceLevelUp::updateState(GameState gameState)
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

void ExpandSequenceLevelUp::playLevelUpAnimation()
{
    SignalsDisplay().all.blink(300, 3);
}
