#ifndef STAGESLOCATOR_H
#define STAGESLOCATOR_H

#include "StartupStage.h"
#include "PlaySequenceStage.h"

class StagesLocator 
{
  public: 
    const StartupStage* startupStage = new StartupStage(this);
    const PlaySequenceStage* playSequenceStage = new PlaySequenceStage(this);
};

#endif // !STAGESLOCATOR_H