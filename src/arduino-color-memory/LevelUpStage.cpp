#include "const.h"
#include "LevelUpStage.h"
#include "StagesLocator.h"
#include "ExtendSequenceLevelUp.h"

StageInterface *LevelUpStage::run()
{
    playLevelUpAnimation();
    showLevelTransition(gameState.level, gameState.level + 1);
    gameState.level++;
    delay(1500);
    dashboard->clear();

    return stagesLocator->playRoundStage
        ->setGameState(
            applyPowerUps(
                levelUp(gameState)
            )
        );
}

GameState LevelUpStage::applyPowerUps(GameState gameState)
{
    int levelJustPlayed = gameState.level - 1;
    if (levelJustPlayed % 5 != 0) {
        return gameState;
    }

    GameState updatedGameState = gameState;

    int const maxLives = 5;
    updatedGameState.lives = min(updatedGameState.lives + 3, maxLives);

    showLivesTransition(gameState.lives, updatedGameState.lives);

    return updatedGameState;
}

LevelUpStage* LevelUpStage::setGameState(GameState gameState)
{
    this->gameState = gameState;
    return this;
}

LevelUpStage *LevelUpStage::reset()
{
    levelUpIndex = 0;
    
    return this;
}

void LevelUpStage::playLevelUpAnimation() 
{
    SignalsDisplay signals;
    signals.all.blink(300, 3);
}

GameState LevelUpStage::levelUp(GameState gameState)
{
    GameState updatedGameState = getLevelUpFor(gameState)->updateState(gameState);
    updatedGameState.roundsLeft = updatedGameState.levelOptions.roundsToPlay;

    return updatedGameState;
}

void LevelUpStage::showLevelTransition(int from, int to)
{
    dashboard->showLevelTransition(from, to);
}

void LevelUpStage::showLivesTransition(int from, int to)
{
    dashboard->showLivesLeftTransition(from, to);
    delay(1000);
}

LevelUpInterface *LevelUpStage::getLevelUpFor(GameState gameState)
{
    LevelUpInterface* selectedLevelUp;
    
    do {
        selectedLevelUp = levelUps[nextLevelUpIndex()];
    } while (!selectedLevelUp->canHandle(gameState));

    return selectedLevelUp;
}

int LevelUpStage::nextLevelUpIndex()
{
    int nextIndex = levelUpIndex;
    
    if (levelUpIndex < levelUpsCount - 1) {
        levelUpIndex++;
    } else {
        levelUpIndex = 0;
    }

    return nextIndex;
}
