#if !defined(EXPERIMENTSTAGE_H)
#define EXPERIMENTSTAGE_H

#include "BaseStage.h"

class ExperimentStage: public BaseStage
{
    using BaseStage::BaseStage;

    public: 
        StageInterface* run();
};

#endif // EXPERIMENTSTAGE_H
