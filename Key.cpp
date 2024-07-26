#include <Arduino.h>
#include "Key.h"

void Key::updateReading()
{
    int reading;

    reading = digitalRead(pin);

    if (reading != lastState) {
        lastState = reading;
        lastDebounceTime = millis();
    }

    if (millisSinceLastDebounceTime() <= debounceDelay) {
        return;
    }

    if (reading == buttonState) {
        return;
    }

    buttonState = reading;
}

unsigned long Key::millisSinceLastDebounceTime()
{
    return millis() - lastDebounceTime;
}

Key::Key(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

bool Key::isUp()
{
    updateReading();
    switch (buttonState)
    {
    case HIGH:
        return false;
    default:
        return true;
    }
}

bool Key::isDown()
{
    return !isUp();
}
