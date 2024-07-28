#include "const.h"
#include "RoundLostStage.h"
#include "StagesLocator.h"
#include "SignalsDisplay.h"

void RoundLostStage::playRoundLostAnimation()
{
    SignalsDisplay signals;
    signals.red.blink(1000, 1);
}

void RoundLostStage::waitForKey()
{
    Key key(START_KEY);

    while(key.isUp());
}

StageInterface *RoundLostStage::run()
{
    playRoundLostAnimation();
    waitForKey();

    return stagesLocator->playRoundStage;
}