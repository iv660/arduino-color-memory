#ifndef LEVELUPSTAGE_H
#define LEVELUPSTAGE_H

#include "const.h"

#include "BaseStage.h"
#include "LevelUpInterface.h"
#include "ExtendSequenceLevelUp.h"
#include "AddLightsLevelUp.h"
#include "DashboardDisplay.h"

class StageInterface;

class LevelUpStage : public BaseStage 
{
    private: 
        GameState gameState;
        
        LevelUpInterface* levelUps[2] = {
            new ExtendSequenceLevelUp(),
            new AddLightsLevelUp(),
        };
        int levelUpIndex = 0;
        int levelUpsCount = 2;

        GameState levelUp(GameState gameState);
        void showLevelTransition(int from, int to);
        void playLevelUpAnimation();
        int nextLevelUpIndex();
        LevelUpInterface* getLevelUpFor(GameState gameState);
    public:
        using BaseStage::BaseStage;

        StageInterface* run();
        LevelUpStage* setGameState(GameState gameState);
        LevelUpStage* reset();
};

#endif // LEVELUPSTAGE_H