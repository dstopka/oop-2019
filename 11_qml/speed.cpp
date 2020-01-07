#include "speed.h"
#include <QDebug>

Speed::Speed(QObject *parent) : QObject(parent)
{

}

void Speed::setValue(float v)
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
            emit speedChanged(getValue());
        }
        else
        {
            firstValue = secondValue;
            secondValue = v;
            emit speedChanged(getValue());
        }

}

float Speed::getValue() const
{
    return secondValue - firstValue;
}
