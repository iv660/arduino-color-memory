#ifndef STAGESLOCATOR_H
#define STAGESLOCATOR_H

#include "StartupStage.h"
#include "PlayRoundStage.h"
#include "RoundWonStage.h"
#include "RoundLostStage.h"
#include "ExperimentStage.h"
#include "LevelUpStage.h"
#include "ServiceLocator.h"
#include "ResetLevelStage.h"
#include "ResetRoundStage.h"
#include "ConfirmRoundStartStage.h"

class StagesLocator 
{
  private:
    ServiceLocator* serviceLocator = new ServiceLocator;
  public: 
    StartupStage* startupStage = 
      new StartupStage(this, serviceLocator);
    PlayRoundStage* playRoundStage = 
      new PlayRoundStage(this, serviceLocator);
    RoundWonStage* roundWonStage = 
      new RoundWonStage(this, serviceLocator);
    RoundLostStage* roundLostStage = 
      new RoundLostStage(this, serviceLocator);
    LevelUpStage* levelUpStage = 
      new LevelUpStage(this, serviceLocator);
    ResetLevelStage* resetLevelStage =
      new ResetLevelStage(this, serviceLocator);
    ResetRoundStage* resetRoundStage =
      new ResetRoundStage(this, serviceLocator);
    ConfirmRoundStartStage* confirmRoundStartStage =
      new ConfirmRoundStartStage(this, serviceLocator);

    ExperimentStage* experimentStage = 
      new ExperimentStage(this, serviceLocator);

};

#endif // !STAGESLOCATOR_H