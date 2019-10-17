#include "TextWrapper.h"

int TextWrapper::columns() const {
    return 10;
}

int TextWrapper::setColumnsNo(const int &i) {
    columnsNo = i;
    return columnsNo;
}

std::string TextWrapper::getText(std::string str){
    text = str;
    return text;
}

std::string TextWrapper::wrapText()
{
    if(text.size() > columnsNo)
    {
        for(unsigned long i = columnsNo; i < text.size(); i += columnsNo)
        {
            if(!text.compare(i, 1, " "))
            {
                text.replace(i, 1, "\n");
                i += columnsNo;
            }
            else
            {
                if(text.find_last_of(" ", i) != std::string::npos)
                {
                    std::string str = text.substr(text.find_last_of(" ", i), columnsNo + 1);
                    if(str.back() == ' ' || str.length() <= columnsNo + 1)
                    {
                        text.insert(text.find_last_of(" ", i)+1, "\n");
                    }
                }
                else
                    text.insert(i++, "\n");
            }
        }
        return text;
    }
    else
        return text;
}