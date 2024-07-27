#ifndef BASESTAGE_H
#define BASESTAGE_H

#include "StageInterface.h"

class StagesLocator;

class BaseStage: public StageInterface
{
  protected:
    StagesLocator* stagesLocator;
  public: 
    BaseStage(StagesLocator* stagesLocator);
};

#endif // !BASESTAGE_H