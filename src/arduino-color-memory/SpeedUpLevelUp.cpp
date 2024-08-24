#include "SpeedUpLevelUp.h"

GameState SpeedUpLevelUp::speedUp(GameState gameState)
{
    if (gameState.levelOptions.sequenceDisplayDuration > 100) {
        gameState.levelOptions.sequenceDisplayDuration -= 100;
    }

    if (gameState.levelOptions.sequenceDisplayPause > 100) {
        gameState.levelOptions.sequenceDisplayPause -= 100;
    }

    return gameState;
}

GameState SpeedUpLevelUp::resetSequenceLength(GameState gameState)
{
    gameState.levelOptions.sequenceLength = 3;

    return gameState;
}

GameState SpeedUpLevelUp::updateState(GameState gameState)
{
    if (!canHandle(gameState)) {
        return gameState;
    }

    GameState updatedGameState = gameState;

    updatedGameState = speedUp(updatedGameState);
    updatedGameState = resetSequenceLength(updatedGameState);

    return updatedGameState;
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