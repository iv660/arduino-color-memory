#ifndef STARTUPSTAGE_H
#define STARTUPSTAGE_H

#include "BaseStage.h"
#include "StageInterface.h"
#include "GameState.h"

class StartupStage: public BaseStage
{
  using BaseStage::BaseStage;

  private:
    GameState gameState;

    void showHighScore();
    void waitForKeyPress();
    void shuffleRandomGenerator();

  public: 
    StageInterface* run();
};

#endif // !STARTUPSTAGE_H