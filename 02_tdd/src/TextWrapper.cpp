#include "TextWrapper.h"

int TextWrapper::columns() const {
    return 10;
}

int TextWrapper::setColumnsNo(int i) {
    columnsNo = i;
    return columnsNo;
}