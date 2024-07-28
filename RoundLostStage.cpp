#include "const.h"
#include "RoundLostStage.h"
#include "StagesLocator.h"
#include "SignalsDisplay.h"

void RoundLostStage::playRoundLostAnimation()
{
    SignalsDisplay signals;
    signals.red.blink(1500, 1);
}

void RoundLostStage::waitForKey()
{
    Key key(START_KEY);

    while(key.isUp());
}

LevelOptions RoundLostStage::resetLevel(LevelOptions levelOptions)
{
    levelOptions.sequenceLength = 1;

    return levelOptions;
}

StageInterface *RoundLostStage::run()
{
    playRoundLostAnimation();
    waitForKey();

    return stagesLocator->playRoundStage
        ->setLevelOptions(
            resetLevel(levelOptions)
        );
}

RoundLostStage * RoundLostStage::setLevelOptions(LevelOptions levelOptions)
{
    this->levelOptions = levelOptions;
    return this;
}
