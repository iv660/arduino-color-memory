#include "AddRoundsLevelUp.h"

GameState AddRoundsLevelUp::updateState(GameState gameState)
{
    gameState.levelOptions.roundsToPlay++;

    return gameState;
}

bool AddRoundsLevelUp::canHandle(GameState gameState)
{
    return true;
}
