#include <Arduino.h>
#include "PlaySequenceStage.h"
#include "StageInterface.h"
#include "StagesLocator.h"

void PlaySequenceStage::waitFor(int pauseMillis)
{
}

StageInterface* PlaySequenceStage::run() 
{
    sequence.generate(sequenceLength);
    while (sequence.hasNext()) {
        waitFor(pause);
        sequenceDisplay.show(sequence.next(), duration);
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

