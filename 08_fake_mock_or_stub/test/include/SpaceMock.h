#pragma once

#include "TestIncludes.h"
#include "SpaceImpl.h"

class SpaceMock : public SpaceImpl {
public:
    MOCK_METHOD1(create, void(unsigned int dimensions));
    MOCK_CONST_METHOD0(dimensions, unsigned int());
};