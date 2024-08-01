#if !defined(SEQUENCEDISPLAY_H)
#define SEQUENCEDISPLAY_H

#include <Arduino.h>

class SequenceDisplay
{
    private:
        int valuePins[5] = {PIN3, PIN5, PIN7, 9, 11};
        int getOutputPinFor(int value);
    public:
        void show(int value, int durationMillis);
};

#endif // SEQUENCEDISPLAY_H
