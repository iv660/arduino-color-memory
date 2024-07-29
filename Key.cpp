#include <Arduino.h>
#include "Key.h"

void Key::updateReading()
{
    int reading;

    reading = digitalRead(pin);

    if (stateIsChanged(reading)) {
        setMomentaryState(reading);
    }

    if (shouldDebounce()) {
        return;
    }

    setPersistantState(reading);
}

bool Key::stateIsChanged(int newState)
{
    if (newState == momentaryState) {
        return false;
    }

    return true;
}

void Key::setMomentaryState(int newState)
{
    lastDebounceTime = millis();
    momentaryState = newState;
}

void Key::setPersistantState(int newState)
{
    persistantState = newState;
}

bool Key::shouldDebounce()
{
    if (millis() - lastDebounceTime <= debounceDelay) {
        return true;
    }

    return false;
}

Key::Key(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

bool Key::isUp()
{
    updateReading();

    if (persistantState == HIGH) {
        return false;
    }

    return true;
}

bool Key::isDown()
{
    return !isUp();
}
