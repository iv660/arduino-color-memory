#if !defined(ROUNDLOSTSTAGE_H)
#define ROUNDLOSTSTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"

class RoundLostStage: public BaseStage
{
    using BaseStage::BaseStage;
    
    private:
        void playRoundLostAnimation();
        void waitForKey();
    public:
        StageInterface* run();
};

#endif // ROUNDLOSTSTAGE_H
