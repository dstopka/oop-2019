#ifndef INC_06_OBSERVER_PATTERN_OBSERVER_H
#define INC_06_OBSERVER_PATTERN_OBSERVER_H

class Observer{
public:
    virtual void notify(float x) = 0;
};

#endif //INC_06_OBSERVER_PATTERN_OBSERVER_H
