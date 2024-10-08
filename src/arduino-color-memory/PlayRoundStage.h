#ifndef PLAYROUNDSTAGE_H
#define PLAYROUNDSTAGE_H

#include "const.h"
#include "BaseStage.h"
#include "StageInterface.h"
#include "Sequence.h"
#include "SequenceDisplay.h"
#include "Keypad.h"
#include "SignalsDisplay.h"
#include "LevelOptions.h"
#include "GameState.h"
#include "DashboardDisplay.h"

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
    GameState gameState;
    int sequenceLength = 1;
    int minValue = 1;
    int getSequenceLenght();

    // Actions
    void waitFor(int pauseMillis);
    void playSequence();
    void playReadyForInputAnimation();
    bool checkInputAgainstSequence();
    void showRoundsLeft();

    // Factory methods
    StageInterface* getNextStage(bool inputIsCorrect);

  public:
    StageInterface* run();
    PlayRoundStage* setGameState(GameState gameState);
};

#endif // !PLAYROUNDSTAGE_H