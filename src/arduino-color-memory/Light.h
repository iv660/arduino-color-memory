#if !defined(LIGHT_H)
#define LIGHT_H

class Light
{
    private:
        int pin;
    public:
        Light(int pin);
        void on();
        void off();
        void blink(int cycleMillis, int repeat);
};

#endif // LIGHT_H
