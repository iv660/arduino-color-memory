#include "SpeedUpLevelUp.h"

GameState SpeedUpLevelUp::updateState(GameState gameState)
{
    if (!canHandle(gameState)) {
        return gameState;
    }

    if (gameState.levelOptions.sequenceDisplayDuration > 100) {
        gameState.levelOptions.sequenceDisplayDuration -= 100;
    }

    if (gameState.levelOptions.sequenceDisplayPause > 100) {
        gameState.levelOptions.sequenceDisplayPause -= 100;
    }

    return gameState;
}

bool SpeedUpLevelUp::canHandle(GameState gameState)
{
    if (gameState.levelOptions.sequenceDisplayDuration > 100) {
        return true;
    }

    if (gameState.levelOptions.sequenceDisplayPause > 100) {
        return true;
    }

    return false;
}