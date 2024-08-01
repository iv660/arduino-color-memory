#if !defined(ROUNDWONSTAGE_H)
#define ROUNDWONSTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"
#include "LevelOptions.h"
#include "SignalsDisplay.h"
#include "GameState.h"

class RoundWonStage: public BaseStage
{
    using BaseStage::BaseStage;
    
    private:
        void playRoundWonAnimation();
        void waitForKey();
        bool isReadyForNextLevel();
        void nextRound();

        StageInterface* getNextStage();

        GameState gameState;
        SignalsDisplay signals;
    public:
        StageInterface* run();
        RoundWonStage* setGameState(GameState gameState);
};

#endif // ROUNDWONSTAGE_H
