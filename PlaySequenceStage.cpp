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
    display.red.blink(100, 2);

  return mStagesLocator->startupStage;
}

