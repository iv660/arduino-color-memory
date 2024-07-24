#if !defined(SIGNALSDISPLAY_H)
#define SIGNALSDISPLAY_H

#include <Arduino.h>
#include "Light.h"
#include "MultiLight.h"

class SignalsDisplay 
{
    public:
        Light red = (PIN3);
        Light yellow = (PIN5);
        Light white = (PIN7);
        Light green = (9);
        Light blue = (11);
        MultiLight all = MultiLight((int []){PIN3, PIN5, PIN7, 9, 11});
};

#endif // SIGNALSDISPLAY_H
