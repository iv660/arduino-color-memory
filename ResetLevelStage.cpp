#include "ResetLevelStage.h"
#include "StagesLocator.h"

GameState ResetLevelStage::resetLevel(GameState gameState)
{
    GameState cleanGameState;

    stagesLocator->levelUpStage->reset();

    return cleanGameState;
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
