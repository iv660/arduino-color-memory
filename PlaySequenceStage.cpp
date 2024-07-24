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
//   for (int i = 100; i <= 800; i += 100) {
//     digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
//     delay(i);                      // wait for a second
//     digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
//     delay(i);                      // wait for a second
//   }

//   for (int i = 700; i >= 100; i -= 100) {
//     digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
//     delay(i);                      // wait for a second
//     digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
//     delay(i);                      // wait for a second
//   }

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

