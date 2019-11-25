#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONGNOMEWIDGET_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONGNOMEWIDGET_H

#include "Widget.h"

class ButtonGnomeWidget : public Widget{
public:
    ButtonGnomeWidget(int kdeVersion);
    void draw();

private:
    int gnomeVersion;
};

#endif //INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONGNOMEWIDGET_H
