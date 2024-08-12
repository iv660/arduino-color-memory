#if !defined(KEY_H)
#define KEY_H

#include <Arduino.h>

class Key
{
private:
    int pin;

    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 50;
    int momentaryState = LOW;
    int persistantState = LOW;

    void updateReading();
    bool stateIsChanged(int newState);
    void setMomentaryState(int newState);
    void setPersistantState(int newState);
    bool shouldDebounce();
public:
    Key(int pin);
    bool isUp();
    bool isDown();
};


#endif // KEY_H
