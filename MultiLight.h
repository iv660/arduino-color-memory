#if !defined(MULTILIGHT_H)
#define MULTILIGHT_H

#include "Light.h"

class MultiLight
{
    private: 
        int pins[5];
    public:
        explicit MultiLight(int pins[5]);
        void on();
        void off();
        void blink(int cycleMillis, int repeat);
};

#endif // MULTILIGHT_H
