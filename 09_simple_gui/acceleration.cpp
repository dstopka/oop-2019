#include "acceleration.h"
#include <QDebug>

Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}

void Acceleration::onChange(double v)
{
    if (!hasFirstValue)
        {
            firstValue = v;
            hasFirstValue = true;
        }
        else if (!hasSecondValue)
        {
            secondValue = v;
            hasSecondValue = true;
        }
        else if (!hasThirdValue)
        {
            thirdValue = v;
            hasThirdValue = true;
        }
        else
        {
            firstValue = secondValue;
            secondValue = thirdValue;
            thirdValue = v;
            emit changed((thirdValue - secondValue) - (secondValue - firstValue));
        }

}
