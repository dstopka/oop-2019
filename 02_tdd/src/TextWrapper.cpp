#include "TextWrapper.h"

int TextWrapper::columns() const {
    return 10;
}

int TextWrapper::setColumnsNo(int i) {
    columnsNo = i;
    return columnsNo;
}

std::string TextWrapper::getText(std::string str){
    text = str;
    return text;
}

std::string TextWrapper::wrapText() {
    if(text.size() > columnsNo)
    {
        for(int i = columnsNo; i < text.size(); i += columnsNo)
        {
            text.insert(i++, "\n");
        }
        return text;
    }
    else
        return text;
}