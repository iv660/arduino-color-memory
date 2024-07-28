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
        void playLevelUpAnimation();
        void waitForKey();

        GameState gameState;
        SignalsDisplay signals;

        GameState levelUp(GameState gameState);
    public:
        StageInterface* run();
        RoundWonStage* setGameState(GameState gameState);
};

#endif // ROUNDWONSTAGE_H
