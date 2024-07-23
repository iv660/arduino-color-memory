#include <Arduino.h>
#include "PlaySequenceStage.h"
#include "StageInterface.h"
#include "StagesLocator.h"

StageInterface* PlaySequenceStage::run() {
  for (int i = 100; i <= 800; i += 100) {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(i);                      // wait for a second
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(i);                      // wait for a second
  }

  for (int i = 700; i >= 100; i -= 100) {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(i);                      // wait for a second
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(i);                      // wait for a second
  }

  return mStagesLocator->startupStage;
}

