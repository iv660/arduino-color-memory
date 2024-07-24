#include <Arduino.h>
#include "PlaySequenceStage.h"
#include "StageInterface.h"
#include "StagesLocator.h"

void PlaySequenceStage::waitFor(int pauseMillis)
{
    delay(pauseMillis);
}

StageInterface* PlaySequenceStage::run() 
{
    sequence.generate(sequenceLength);
    while (sequence.hasNext()) {
        sequenceDisplay.show(sequence.next(), duration);
        waitFor(pause);
    }

    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);

  return mStagesLocator->startupStage;
}

