#if !defined(SEQUENCE_H)
#define SEQUENCE_H

class Sequence 
{
    private:
        int shown = 0;
        int length = 1;
    public:
        bool hasNext();
        int next();
        void generate(int length);
};

#endif // SEQUENCE_H
