#include "Displacement.h"

void Displacement::set(float x)
{
    this->value = x;
    notifyObservers(x);
}
