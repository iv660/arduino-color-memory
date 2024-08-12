#if !defined(RESETROUNDSTAGE_H)
#define RESETROUNDSTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"
#include "GameState.h"

class ResetRoundStage: public BaseStage
{
    private:
        GameState gameState;

        void playResetRoundAnimation();
        GameState resetRound(GameState gameState);
    public:
        using BaseStage::BaseStage;

        StageInterface* run();
        StageInterface* setGameState(GameState gameState);
};

#endif // RESETROUNDSTAGE_H
