#include <Arduino.h>
#include "SequenceDisplay.h"
#include "Light.h"

void SequenceDisplay::show(int value, int durationMillis)
{
    Light light(LED_BUILTIN);
    light.on();
    delay(durationMillis);
    light.off();
}