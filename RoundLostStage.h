#if !defined(ROUNDLOSTSTAGE_H)
#define ROUNDLOSTSTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"
#include "LevelOptions.h"

class RoundLostStage: public BaseStage
{
    using BaseStage::BaseStage;
    
    private:
        void playRoundLostAnimation();
        void waitForKey();
        LevelOptions levelOptions;
        LevelOptions resetLevel(LevelOptions levelOptions);

    public:
        StageInterface* run();
        RoundLostStage* setLevelOptions(LevelOptions levelOptions);
};

#endif // ROUNDLOSTSTAGE_H
