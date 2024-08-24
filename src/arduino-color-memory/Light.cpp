#include <Arduino.h>
#include "Light.h"

Light::Light(int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void Light::on()
{
    digitalWrite(pin, HIGH);
}

void Light::off()
{
    digitalWrite(pin, LOW);
}

void Light::blink(int cycleMillis, int repeat)
{
    for (int i = 1; i <= repeat; i++) {
        on();
        delay(cycleMillis / 2);
        off();
        delay(cycleMillis / 2);
    }
}
