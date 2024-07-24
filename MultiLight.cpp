#include <Arduino.h>
#include "MultiLight.h"

MultiLight::MultiLight(int pins[5])
{
    for (int index = 0; index <= 4; index++) {
        this->pins[index] = pins[index];
    }
}

void MultiLight::on()
{
    for (int index = 0; index <= 4; index++) {
        Light light(pins[index]);
        light.on();
    } 
}

void MultiLight::off()
{
    for (int index = 0; index <= 4; index++) {
        Light light(pins[index]);
        light.off();
    }
}

void MultiLight::blink(int cycleMillis, int repeat)
{
    for (int i = 1; i <= repeat; i++) {
        on();
        delay(cycleMillis / 2);
        off();
        delay(cycleMillis / 2);
    }
}
