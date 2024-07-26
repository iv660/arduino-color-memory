#if !defined(SEQUENCE_H)
#define SEQUENCE_H

class Sequence 
{
    private:
        int values[99];
        int length;
        int pointer = 0;

        int getPointer();
        int nextPointer();
    public:
        bool hasNext();
        int next();
        void generate(int length, int minValue, int maxValue);
        bool checkInput(int index, int input);
};

#endif // SEQUENCE_H
