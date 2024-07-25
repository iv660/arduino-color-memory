#ifndef PLAYROUNDSTAGE_H
#define PLAYROUNDSTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"
#include "Sequence.h"
#include "SequenceDisplay.h"

class PlayRoundStage: public BaseStage
{
  using BaseStage::BaseStage;
  private:
    Sequence sequence;
    SequenceDisplay sequenceDisplay;
    int duration = 700;
    int pause = 300;
    int sequenceLength = 5;
    int minValue = 1;
    int maxValue = 3;

    void waitFor(int pauseMillis);
    void playSequence();
    void playReadyForInputAnimation();
    bool checkInputAgainstSequence();
    StageInterface* getNextStage(bool inputIsCorrect);

  public:
    StageInterface* run();
};

#endif // !PLAYROUNDSTAGE_H