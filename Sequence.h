#if !defined(SEQUENCE_H)
#define SEQUENCE_H

class Sequence 
{
    private:
        int sequence[99];
        int length;
        int shown = 0;

        int getPointer();
        int nextPointer();
    public:
        bool hasNext();
        int next();
        void generate(int length, int minValue, int maxValue);
};

#endif // SEQUENCE_H
