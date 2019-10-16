#pragma once

#include <cstdio>
#include <cstring>
#include <iostream>

class TextWrapper{
private:
    int columnsNo;
    std::string text;
public:
    int columns() const;
    int setColumnsNo(const int &i);
    std::string getText(std::string str);
    std::string wrapText();
};
