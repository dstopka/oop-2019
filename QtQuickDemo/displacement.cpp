#include "displacement.h"
#include <QDebug>

Displacement::Displacement(QObject *parent) : QObject(parent)
{

}

void Displacement::setDisplacement(double v)
{
    value = v;
    qDebug() << getDisplacement();
    emit displacementChanged(getDisplacement());
}

double Displacement::getDisplacement() const
{
    return value;
}
