#if !defined(RESETROUNDSTAGE_H)
#define RESETROUNDSTAGE_H

#include "BaseStage.h"

class ResetRoundStage: public BaseStage
{
    private:
    public:
        using BaseStage::BaseStage;

        StageInterface* run();
};

#endif // RESETROUNDSTAGE_H
