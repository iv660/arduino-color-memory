#ifndef STARTUPSTAGE_H
#define STARTUPSTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"

class StartupStage: public BaseStage
{
  using BaseStage::BaseStage;

  private:
    void waitForAnyKey();

  public: 
    StageInterface* run();
};

#endif // !STARTUPSTAGE_H