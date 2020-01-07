#include "speed.h"
#include <QDebug>

Speed::Speed(QObject *parent) : QObject(parent)
{

}

void Speed::setSpeed(double v)
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
        else
        {
            firstValue = secondValue;
            secondValue = v;
            value = secondValue - firstValue;
            emit changed(getSpeed());
        }

}

float Speed::getSpeed()
{
    return value;
}
