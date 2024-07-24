#include <Arduino.h>
#include "PlaySequenceStage.h"
#include "StageInterface.h"
#include "StagesLocator.h"
#include "Light.h"

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

    Light light(LED_BUILTIN);
    light.on();
    delay(100);
    light.off();
    delay(100);
    light.on();
    delay(100);
    light.off();
    delay(100);

  return mStagesLocator->startupStage;
}

