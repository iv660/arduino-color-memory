#ifndef STAGESLOCATOR_H
#define STAGESLOCATOR_H

#include "StartupStage.h"
#include "PlayRoundStage.h"
#include "RoundWonStage.h"
#include "RoundLostStage.h"
#include "ExperimentStage.h"

class StagesLocator 
{
  public: 
    StartupStage* startupStage = new StartupStage(this);
    PlayRoundStage* playRoundStage = new PlayRoundStage(this);
    RoundWonStage* roundWonStage = new RoundWonStage(this);
    RoundLostStage* roundLostStage = new RoundLostStage(this);
    ExperimentStage* experimentStage = new ExperimentStage(this);
};

#endif // !STAGESLOCATOR_H