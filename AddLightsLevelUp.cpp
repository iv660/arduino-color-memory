#include "AddLightsLevelUp.h"

GameState AddLightsLevelUp::updateState(GameState gameState)
{
    if (!canHandle(gameState)) {
        return gameState;
    }
    
    gameState.levelOptions.maxValue++;

    return gameState;
}

bool AddLightsLevelUp::canHandle(GameState gameState)
{
    return gameState.levelOptions.maxValue < 5;
}