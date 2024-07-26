#if !defined(KEY_H)
#define KEY_H

#include <Arduino.h>

class Key
{
private:
    int pin;
    int lastState = LOW;
    int buttonState = LOW;
    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 50;

    void updateReading();
    unsigned long millisSinceLastDebounceTime();
public:
    Key(int pin);
    bool isUp();
    bool isDown();
};


#endif // KEY_H
