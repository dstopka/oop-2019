#pragma once

class TextWrapper{
private:
    int columnsNo;
public:
    int columns() const;
    int setColumnsNo(int i);
};
