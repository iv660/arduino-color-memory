#if !defined(SEQUENCEDISPLAY_H)
#define SEQUENCEDISPLAY_H

class SequenceDisplay
{
    private:
        int valuePins[2] = {PIN3, PIN5};
        int getOutputPinFor(int value);
    public:
        void show(int value, int durationMillis);
};

#endif // SEQUENCEDISPLAY_H
