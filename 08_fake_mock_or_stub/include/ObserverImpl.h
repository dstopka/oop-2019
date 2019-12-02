#pragma once

#include "Observer.h"
#include <map>

class ObserverImpl : public Observer {
public:

    void remember(std::string question, std::string answer) override;
    std::string answer(std::string question) const override;

private:
    std::map<std::string, std::string> answers;
};
