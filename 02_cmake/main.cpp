#include <iostream>
#include "dummy.h"

int main()
{
    auto dummy = Dummy{};
    using namespace std;
    cout << dummy.add(7, 3);
}