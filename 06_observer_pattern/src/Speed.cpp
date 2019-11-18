#include "Speed.h"

void Speed::notify(float x)
{
    if (!hasFirstValue)
    {
        firstValue = x;
        hasFirstValue = true;
    }
    else if (!hasSecondValue)
    {
        secondValue = x;
        hasSecondValue = true;
    }
    else
    {
        firstValue = secondValue;
        secondValue = x;
    }
}

float Speed::get()
{
    return secondValue - firstValue;
}