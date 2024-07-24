#include <Arduino.h>
#include "PlaySequenceStage.h"
#include "StageInterface.h"
#include "StagesLocator.h"
#include "Light.h"
#include "SignalsDisplay.h"

void PlaySequenceStage::waitFor(int pauseMillis)
{
    delay(pauseMillis);
}

StageInterface* PlaySequenceStage::run() 
{
    sequence.generate(sequenceLength, minValue, maxValue);
    while (sequence.hasNext()) {
        sequenceDisplay.show(sequence.next(), duration);
        waitFor(pause);
    }

    SignalsDisplay display;
    display.all.blink(100, 1);

  return mStagesLocator->startupStage;
}

