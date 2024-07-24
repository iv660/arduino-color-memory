#ifndef PLAYSEQUENCESTAGE_H
#define PLAYSEQUENCESTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"
#include "Sequence.h"
#include "SequenceDisplay.h"

class PlaySequenceStage: public BaseStage
{
  using BaseStage::BaseStage;
  private:
    Sequence sequence;
    SequenceDisplay sequenceDisplay;
    int duration = 700;
    int pause = 300;
    int sequenceLength = 2;

    void waitFor(int pauseMillis);

  public:
    StageInterface* run();
};

#endif // !PLAYSEQUENCESTAGE_H