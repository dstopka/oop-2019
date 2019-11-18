#ifndef INC_06_OBSERVER_PATTERN_DISPLACEMENT_H
#define INC_06_OBSERVER_PATTERN_DISPLACEMENT_H

#include "Observable.h"

class Displacement : public Observable {
private:
    float value;
public:
    void set(float x);
};

#endif //INC_06_OBSERVER_PATTERN_DISPLACEMENT_H
