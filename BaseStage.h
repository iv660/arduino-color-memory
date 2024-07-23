#ifndef BASESTAGE_H
#define BASESTAGE_H

#include "StageInterface.h"
// #include "StagesLocator.h"

class StagesLocator;

class BaseStage: public StageInterface
{
  public: 
    BaseStage(StagesLocator* stagesLocator) {
      mStagesLocator = stagesLocator;
    }
};

#endif // !BASESTAGE_H