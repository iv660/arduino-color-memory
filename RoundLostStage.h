#if !defined(ROUNDLOSTSTAGE_H)
#define ROUNDLOSTSTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"
#include "GameState.h"

class RoundLostStage: public BaseStage
{
    using BaseStage::BaseStage;
    
    private:
        void playRoundLostAnimation();
        void waitForKey();
        GameState gameState;
        GameState resetLevel(GameState gameState);

    public:
        StageInterface* run();
        RoundLostStage* setGameState(GameState gameState);
};

#endif // ROUNDLOSTSTAGE_H
