#include <Arduino.h>
#include "PlayRoundStage.h"
#include "StageInterface.h"
#include "StagesLocator.h"
#include "Light.h"
#include "SignalsDisplay.h"

void PlayRoundStage::waitFor(int pauseMillis)
{
    delay(pauseMillis);
}

StageInterface* PlayRoundStage::run() 
{
    playSequence();
    playReadyForInputAnimation();
    bool inputIsCorrect = checkInputAgainstSequence();
    
    return getNextStage(inputIsCorrect);
}

void PlayRoundStage::playSequence()
{
    sequence.generate(sequenceLength, minValue, maxValue);
    while (sequence.hasNext()) {
        sequenceDisplay.show(sequence.next(), duration);
        waitFor(pause);
    }
}

void PlayRoundStage::playReadyForInputAnimation()
{
    SignalsDisplay display;
    display.all.blink(100, 1);
}

bool PlayRoundStage::checkInputAgainstSequence()
{
    return false;
}

StageInterface* PlayRoundStage::getNextStage(bool inputIsCorrect)
{
    return stagesLocator->startupStage;
}
