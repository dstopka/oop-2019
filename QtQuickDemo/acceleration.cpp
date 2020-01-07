#include "acceleration.h"
#include <QDebug>

Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}

void Acceleration::setAcc(double v)
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
            value = (thirdValue - secondValue) - (secondValue - firstValue);
            emit changed(getAcc());
        }
}

float Acceleration::getAcc()
{
      return value;
}

