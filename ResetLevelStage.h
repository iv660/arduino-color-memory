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
        void playResetLevelAnimation();
        void showLevelTransition(int from, int to);
    public:
        StageInterface* run();
        StageInterface* setGameState(GameState gameState);
};


#endif // RESETLEVELSTAGE_H
