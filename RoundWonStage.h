#if !defined(ROUNDWONSTAGE_H)
#define ROUNDWONSTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"

class RoundWonStage: public BaseStage
{
    using BaseStage::BaseStage;
    
    private:
        void playRoundWonAnimation();
        void waitForKey();
    public:
        StageInterface* run();
};

#endif // ROUNDWONSTAGE_H
