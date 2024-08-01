#include <Arduino.h>
#include "ExtendSequenceLevelUp.h"
#include "SignalsDisplay.h"


GameState ExtendSequenceLevelUp::updateState(GameState gameState)
{
    gameState.levelOptions.sequenceLength++;

    return gameState;
}

bool ExtendSequenceLevelUp::canHandle(GameState gameState)
{
    return true;
}
