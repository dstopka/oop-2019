#include "demo.h"


Demo::Demo(QObject*)
{
}

int Demo::add(int a, int b)
{
    emit added();
    return a + b;
}
