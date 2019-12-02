#pragma once

#include "TestIncludes.h"
#include "ObserverImpl.h"

class ObserverMock : public ObserverImpl {
public:
    MOCK_METHOD2(remember, void(std::string question, std::string answer));
    MOCK_CONST_METHOD1(answer, std::string(std::string question));
};