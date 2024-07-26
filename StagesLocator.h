#ifndef STAGESLOCATOR_H
#define STAGESLOCATOR_H

#include "StartupStage.h"
#include "PlayRoundStage.h"
#include "ExperimentStage.h"

class StagesLocator 
{
  public: 
    StartupStage* startupStage = new StartupStage(this);
    PlayRoundStage* playRoundStage = new PlayRoundStage(this);
    ExperimentStage* experimentStage = new ExperimentStage(this);
};

#endif // !STAGESLOCATOR_H