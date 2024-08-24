#if !defined(SIGNALSDISPLAY_H)
#define SIGNALSDISPLAY_H

#include <Arduino.h>
#include "const.h"
#include "Light.h"
#include "MultiLight.h"

class SignalsDisplay 
{
    public:
        Light red = (LIGHT_RED);
        Light yellow = (LIGHT_YELLOW);
        Light white = (LIGHT_WHITE);
        Light green = (LIGHT_GREEN);
        Light blue = (LIGHT_BLUE);
        MultiLight all = MultiLight((int []){PIN3, PIN5, PIN7, 9, 11});
};

#endif // SIGNALSDISPLAY_H
