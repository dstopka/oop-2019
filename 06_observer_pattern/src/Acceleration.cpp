#include "Acceleration.h"

void Acceleration::notify(float x)
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
    else if (!hasThirdValue)
    {
        thirdValue = x;
        hasThirdValue = true;
    }
    else
    {
        firstValue = secondValue;
        secondValue = thirdValue;
        thirdValue = x;
    }
}

float Acceleration::get()
{
    return (thirdValue - secondValue) - (secondValue - firstValue);
}
