#ifndef PLAYROUNDSTAGE_H
#define PLAYROUNDSTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"
#include "Sequence.h"
#include "SequenceDisplay.h"
#include "Keypad.h"
#include "SignalsDisplay.h"
#include "LevelOptions.h"

class PlayRoundStage: public BaseStage
{
  using BaseStage::BaseStage;
  private:
    // Dependencies
    Sequence sequence;
    SequenceDisplay sequenceDisplay;
    SignalsDisplay signalsDisplay;
    Keypad keypad;

    // Gameplay level options
    LevelOptions levelOptions;
    int duration = 700;
    int pause = 300;
    int sequenceLength = 1;
    int minValue = 1;
    int maxValue = 3;
    int getSequenceLenght();

    // Actions
    void waitFor(int pauseMillis);
    void playSequence();
    void playReadyForInputAnimation();
    bool checkInputAgainstSequence();


    // Factory methods
    StageInterface* getNextStage(bool inputIsCorrect);

  public:
    StageInterface* run();
    PlayRoundStage* setLevelOptions(LevelOptions levelOptions);
};

#endif // !PLAYROUNDSTAGE_H