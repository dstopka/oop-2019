#pragma once

#include <stdio.h>
#include <string.h>
#include <iostream>

class TextWrapper{
private:
    int columnsNo;
    std::string text;
public:
    int columns() const;
    int setColumnsNo(int i);
    std::string getText(std::string str);
    std::string wrapText();
};
