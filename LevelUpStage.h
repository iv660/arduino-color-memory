#ifndef LEVELUPSTAGE_H
#define LEVELUPSTAGE_H

#include "BaseStage.h"
#include "LevelUpInterface.h"

class StageInterface;

class LevelUpStage : public BaseStage 
{
    private: 
        GameState gameState;

        void playLevelUpAnimation();
        GameState levelUp(GameState gameState);
    public:
        using BaseStage::BaseStage;

        StageInterface* run();
        LevelUpStage* setGameState(GameState gameState);
};

#endif // LEVELUPSTAGE_H