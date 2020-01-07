#include "displacement.h"
#include <QDebug>

Displacement::Displacement(QObject *parent) : QObject(parent)
{

}

void Displacement::setDisplacement(float v)
{
    value = v;
    emit displacementChanged(getDisplacement());
}

float Displacement::getDisplacement() const
{
    return value;
}
