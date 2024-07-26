#include <Arduino.h>
#include "Sequence.h"

int Sequence::getPointer()
{
    return pointer;
}

int Sequence::nextPointer()
{
    return pointer++;
}

bool Sequence::hasNext()
{
    return pointer <= length - 1;
}

int Sequence::next()
{
    return values[nextPointer()];
}

void Sequence::generate(int length, int minValue, int maxValue)
{
    this->length = length;
    pointer = 0;

    for (int index = 0; index <= length - 1; index++) {
        values[index] = random(minValue, maxValue + 1);
    }
}

bool Sequence::checkInput(int index, int input)
{
    return input == values[index - 1];
}
