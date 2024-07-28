#include "const.h"
#include "RoundWonStage.h"
#include "StagesLocator.h"
#include "SignalsDisplay.h"

void RoundWonStage::playRoundWonAnimation()
{
    SignalsDisplay signals;
    signals.green.blink(500, 1);
}

void RoundWonStage::waitForKey()
{
    Key key(START_KEY);

    while(key.isUp());
}

StageInterface *RoundWonStage::run()
{
    playRoundWonAnimation();
    waitForKey();

    return stagesLocator->playRoundStage;
}