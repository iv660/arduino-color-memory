#if !defined(RESETLEVELSTAGE_H)
#define RESETLEVELSTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"
#include "GameState.h"

class ResetLevelStage: public BaseStage
{
    using BaseStage::BaseStage;

    private:
        GameState gameState;

        GameState resetLevel(GameState gameState);
        int getNewHighScore(int levelReached, int currentHighScore);
        void playResetLevelAnimation();
        void showLevelTransition(int from, int to);
        void showHighScore(int currentHighScore, int newHighScore);
    public:
        StageInterface* run();
        StageInterface* setGameState(GameState gameState);
};


#endif // RESETLEVELSTAGE_H
