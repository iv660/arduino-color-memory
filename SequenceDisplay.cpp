#include <Arduino.h>
#include "SequenceDisplay.h"

void SequenceDisplay::show(int value, int durationMillis)
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(durationMillis);
    digitalWrite(LED_BUILTIN, LOW);
}