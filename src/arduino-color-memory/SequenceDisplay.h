#if !defined(SEQUENCEDISPLAY_H)
#define SEQUENCEDISPLAY_H

#include <Arduino.h>
#include "const.h"

class SequenceDisplay
{
    private:
        int valuePins[5] = {
            VALUE_1_PIN, 
            VALUE_2_PIN, 
            VALUE_3_PIN, 
            VALUE_4_PIN, 
            VALUE_5_PIN
        };
        int getOutputPinFor(int value);
    public:
        void show(int value, int durationMillis);
};

#endif // SEQUENCEDISPLAY_H
