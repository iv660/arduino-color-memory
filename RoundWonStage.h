#if !defined(ROUNDWONSTAGE_H)
#define ROUNDWONSTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"
#include "LevelOptions.h"
#include "SignalsDisplay.h"

class RoundWonStage: public BaseStage
{
    using BaseStage::BaseStage;
    
    private:
        void playRoundWonAnimation();
        void playLevelUpAnimation();
        void waitForKey();

        LevelOptions levelOptions;
        SignalsDisplay signals;

        LevelOptions levelUp(LevelOptions levelOptions);
    public:
        StageInterface* run();
        RoundWonStage* setLevelOptions(LevelOptions levelOptions);
};

#endif // ROUNDWONSTAGE_H
