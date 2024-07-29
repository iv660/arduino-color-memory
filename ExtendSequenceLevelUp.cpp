#include <Arduino.h>
#include "ExtendSequenceLevelUp.h"
#include "SignalsDisplay.h"


GameState ExtendSequenceLevelUp::updateState(GameState gameState)
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

void ExtendSequenceLevelUp::playLevelUpAnimation()
{
    SignalsDisplay().all.blink(300, 3);
}
