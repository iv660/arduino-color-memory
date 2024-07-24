#include "Sequence.h"

bool Sequence::hasNext()
{
    return shown < length;
}

int Sequence::next()
{
    shown++;

    return 1;
}

void Sequence::generate(int length)
{
    this->length = length;
    shown = 0;
}
