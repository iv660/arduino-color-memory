#if !defined(SIGNALSDISPLAY_H)
#define SIGNALSDISPLAY_H

#include <Arduino.h>
#include "Light.h"

class SignalsDisplay 
{
    public:
        Light red = (PIN3);
        Light yellow = (PIN5);
        Light white = (PIN7);
        Light green = (9);
        Light blue = (11);
};

#endif // SIGNALSDISPLAY_H
