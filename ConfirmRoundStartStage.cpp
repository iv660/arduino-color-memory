#include "ConfirmRoundStartStage.h"

#include "const.h"
#include "GameState.h"
#include "Key.h"
#include "StagesLocator.h"

void ConfirmRoundStartStage::waitForKey()
{
    Key key(START_KEY);
    while(key.isUp());
}

/**
 * Runs the ConfirmRoundStartStage by waiting for a key press and then returns the next stage to play the round.
 *
 * @return The next stage to play the round.
 */
StageInterface *ConfirmRoundStartStage::run()
{
    waitForKey();
    return stagesLocator->playRoundStage
        ->setGameState(gameState);
}

StageInterface *ConfirmRoundStartStage::setGameState(GameState gameState)
{
    this->gameState = gameState;
    return this;
}
