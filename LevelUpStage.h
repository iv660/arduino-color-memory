#ifndef LEVELUPSTAGE_H
#define LEVELUPSTAGE_H

#include "BaseStage.h"
#include "LevelUpInterface.h"
#include "ExtendSequenceLevelUp.h"

class StageInterface;

class LevelUpStage : public BaseStage 
{
    private: 
        GameState gameState;

        LevelUpInterface* levelUps[1] = {
            new ExtendSequenceLevelUp()
        };
        int levelUpIndex = 0;
        int levelUpsCount = 1;

        GameState levelUp(GameState gameState);
        void playLevelUpAnimation();
        int nextLevelUpIndex();
        LevelUpInterface* getLevelUpFor(GameState gameState);
    public:
        using BaseStage::BaseStage;

        StageInterface* run();
        LevelUpStage* setGameState(GameState gameState);
};

#endif // LEVELUPSTAGE_H