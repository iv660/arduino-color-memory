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
