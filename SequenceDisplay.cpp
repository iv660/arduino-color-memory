#include <Arduino.h>
#include "SequenceDisplay.h"
#include "Light.h"

int SequenceDisplay::getOutputPinFor(int value)
{
    return valuePins[value - 1];
}

void SequenceDisplay::show(int value, int durationMillis)
{
    Light light(getOutputPinFor(value));
    light.on();
    delay(durationMillis);
    light.off();
}