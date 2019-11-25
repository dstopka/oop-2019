#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_LISTGNOMEWIDGET_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_LISTGNOMEWIDGET_H

#include "Widget.h"

class ListGnomeWidget : public Widget{
public:
    ListGnomeWidget(int kdeVersion);
    void draw();

private:
    int gnomeVersion;
};

#endif //INC_07_ABSTRACT_FACTORY_PATTERN_LISTGNOMEWIDGET_H
