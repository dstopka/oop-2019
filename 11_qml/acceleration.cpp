#include "acceleration.h"
#include <QDebug>

Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}

void Acceleration::setValue(float v)
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
            emit accelerationChanged(getValue());
        }
        else
        {
            firstValue = secondValue;
            secondValue = v;
            emit accelerationChanged(getValue());
        }
}

float Acceleration::getValue()
{
      return secondValue - firstValue;
}

