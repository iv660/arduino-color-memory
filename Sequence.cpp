#include "Arduino.h"
#include "Sequence.h"

int Sequence::getPointer()
{
    return shown;
}

int Sequence::nextPointer()
{
    return shown++;
}

bool Sequence::hasNext()
{
    return shown < length;
}

int Sequence::next()
{
    return sequence[nextPointer()];
}

void Sequence::generate(int length, int minValue, int maxValue)
{
    this->length = length;
    shown = 0;

    for (int index = 0; index <= length - 1; index++) {
        sequence[index] = random(minValue, maxValue + 1);
    }
}
