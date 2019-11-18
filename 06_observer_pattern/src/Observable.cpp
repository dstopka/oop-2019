#include "Observable.h"

void Observable::notifyObservers(float x)
{
    for(auto observer : observers)
        observer->notify(x);
}

void Observable::registerObserver(Observer* observer)
{
    this->observers.insert(observer);
}

void Observable::unregisterObserver(Observer* observer)
{
    this->observers.erase(observer);
}

