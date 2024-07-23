#ifndef PLAYSEQUENCESTAGE_H
#define PLAYSEQUENCESTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"

class PlaySequenceStage: public BaseStage
{
  using BaseStage::BaseStage;
  
  public:
    StageInterface* run();
};

#endif // !PLAYSEQUENCESTAGE_H