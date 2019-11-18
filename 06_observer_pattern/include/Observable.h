#ifndef INC_06_OBSERVER_PATTERN_OBSERVABLE_H
#define INC_06_OBSERVER_PATTERN_OBSERVABLE_H
#include<set>
#include "Observer.h"

class Observable {
private:
    std::set<Observer*> observers;
protected:
    void notifyObservers(float x);
public:
    void registerObserver(Observer* observer);
    void unregisterObserver(Observer* observer);
};


#endif //INC_06_OBSERVER_PATTERN_OBSERVABLE_H
