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

        void playLevelUpAnimation();
        GameState levelUp(GameState gameState);
        LevelUpInterface* getLevelUpFor(GameState gameState);
        int nextLevelUpIndex();
    public:
        using BaseStage::BaseStage;

        StageInterface* run();
        LevelUpStage* setGameState(GameState gameState);
};

#endif // LEVELUPSTAGE_H