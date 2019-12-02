#pragma once

#include "TestIncludes.h"
#include "Time.h"

class TimeMock : public Time {
public:
    MOCK_METHOD1(create, void(bool endless));
    MOCK_CONST_METHOD0(now, long long());
    MOCK_METHOD0(flow, void());
};