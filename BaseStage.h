#ifndef BASESTAGE_H
#define BASESTAGE_H

#include "StageInterface.h"
#include "ServiceLocator.h"

class StagesLocator;

class BaseStage: public StageInterface
{
  protected:
    StagesLocator* stagesLocator;
    ServiceLocator* serviceLocator;
  public: 
    BaseStage(StagesLocator* stagesLocator, ServiceLocator* serviceLocator);
};

#endif // !BASESTAGE_H