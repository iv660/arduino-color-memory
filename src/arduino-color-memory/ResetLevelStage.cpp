#include "ResetLevelStage.h"
#include "StagesLocator.h"
#include "storage/Storage.h"

GameState ResetLevelStage::resetLevel(GameState gameState)
{
    GameState cleanGameState;

    stagesLocator->levelUpStage->reset();

    return cleanGameState;
}

int ResetLevelStage::getNewHighScore(
    int levelReached, int currentHighScore)
{
    return max(currentHighScore, levelReached);
}

/**
 * Runs the ResetLevelStage by resetting the level and returning the next stage to be played.
 *
 * @return Pointer to the next stage to be played
 */
StageInterface *ResetLevelStage::run()
{
    playResetLevelAnimation();
    showLevelTransition(gameState.level, 1);

    GameState nextGameState = resetLevel(gameState);
    nextGameState.highScore = getNewHighScore(
        gameState.level, gameState.highScore);
    showHighScore(gameState.highScore, nextGameState.highScore);

    if (gameState.highScore != nextGameState.highScore) {
        Storage().setHighScore(nextGameState.highScore)
            ->store();
    }

    return stagesLocator->confirmRoundStartStage
        ->setGameState(nextGameState);
}

StageInterface* ResetLevelStage::setGameState(GameState gameState)
{
    this->gameState = gameState;
    return this;
}

void ResetLevelStage::playResetLevelAnimation()
{
    SignalsDisplay signals;
    const int baseDuration = 300;
    for (int i; i <= 20; i += 2) {
        const int cycleDuration = 30 * i;
        const int repeat = 20 / i;
        signals.all.blink(cycleDuration, repeat);
    }
}

void ResetLevelStage::showLevelTransition(int from, int to)
{
    dashboard->showLevelTransition(from, to);
    delay(1500);
    dashboard->clear();
}

void ResetLevelStage::showHighScore(int currentHighScore, int newHighScore)
{
    if (currentHighScore == newHighScore) {
        dashboard->showHighScore(currentHighScore);
    } else {
        dashboard->showHighScoreTransition(currentHighScore, newHighScore);
    }
}
