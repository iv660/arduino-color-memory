#include "ResetRoundStage.h"
#include "StagesLocator.h"

StageInterface *ResetRoundStage::run()
{
    return stagesLocator->playRoundStage;
}