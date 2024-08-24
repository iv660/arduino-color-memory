#ifndef CONFIRMROUNDSTARTSTAGE_H
#define CONFIRMROUNDSTARTSTAGE_H

#include "BaseStage.h"
#include "GameState.h"

class ConfirmRoundStartStage : public BaseStage
{
    using BaseStage::BaseStage;
private:
    GameState gameState;

    void waitForKey();
public:
    virtual StageInterface* run();
    virtual StageInterface* setGameState(GameState gameState);
};

#endif // CONFIRMROUNDSTARTSTAGE_H
