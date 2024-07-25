#ifndef STAGESLOCATOR_H
#define STAGESLOCATOR_H

#include "StartupStage.h"
#include "PlayRoundStage.h"

class StagesLocator 
{
  public: 
    StartupStage* startupStage = new StartupStage(this);
    PlayRoundStage* playRoundStage = new PlayRoundStage(this);
};

#endif // !STAGESLOCATOR_H