#pragma once

class Space{
public:

    virtual void create(unsigned int dimensions) = 0;
    virtual unsigned int dimensions() const = 0;
};