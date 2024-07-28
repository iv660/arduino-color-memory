#include "const.h"
#include "RoundWonStage.h"
#include "StagesLocator.h"
#include "SignalsDisplay.h"

void RoundWonStage::playRoundWonAnimation()
{
    signals.green.blink(1500, 1);
}

void RoundWonStage::playLevelUpAnimation()
{
    signals.all.blink(300, 3);
}

void RoundWonStage::waitForKey()
{
    Key key(START_KEY);

    while(key.isUp());
}

LevelOptions RoundWonStage::levelUp(LevelOptions levelOptions)
{
    levelOptions.roundsToPlay--;
    
    if (levelOptions.roundsToPlay < 1) {
        levelOptions.sequenceLength++;
        levelOptions.roundsToPlay = 5;
        playLevelUpAnimation();
        delay(1000);
    }

    return levelOptions;
}

StageInterface *RoundWonStage::run()
{
    playRoundWonAnimation();
    waitForKey();

    return stagesLocator->playRoundStage
        ->setLevelOptions(levelUp(levelOptions));
}

RoundWonStage *RoundWonStage::setLevelOptions(LevelOptions levelOptions)
{
    this->levelOptions = levelOptions;

    return this;
}
