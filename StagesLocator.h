#ifndef STAGESLOCATOR_H
#define STAGESLOCATOR_H

#include "StartupStage.h"
#include "PlayRoundStage.h"
#include "RoundWonStage.h"
#include "RoundLostStage.h"
#include "ExperimentStage.h"
#include "LevelUpStage.h"

class StagesLocator 
{
  public: 
    StartupStage* startupStage = new StartupStage(this);
    PlayRoundStage* playRoundStage = new PlayRoundStage(this);
    RoundWonStage* roundWonStage = new RoundWonStage(this);
    RoundLostStage* roundLostStage = new RoundLostStage(this);
    LevelUpStage* levelUpStage = new LevelUpStage(this);

    ExperimentStage* experimentStage = new ExperimentStage(this);
};

#endif // !STAGESLOCATOR_H