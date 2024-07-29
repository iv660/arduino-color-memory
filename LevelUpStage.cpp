#include "LevelUpStage.h"
#include "StagesLocator.h"
#include "ExtendSequenceLevelUp.h"

StageInterface *LevelUpStage::run()
{
    playLevelUpAnimation();
    delay(1500);

    return stagesLocator->playRoundStage
        ->setGameState(levelUp(gameState));
}

LevelUpStage* LevelUpStage::setGameState(GameState gameState)
{
    this->gameState = gameState;
    return this;
}

void LevelUpStage::playLevelUpAnimation() 
{
    SignalsDisplay signals;
    signals.all.blink(300, 3);
}

GameState LevelUpStage::levelUp(GameState gameState)
{
    return getLevelUpFor(gameState)->updateState(gameState);
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
    if (levelUpIndex < levelUpsCount - 1) {
        levelUpIndex++;
    } else {
        levelUpIndex = 0;
    }

    return levelUpIndex;
}
