#include <ListKdeWidget.h>
#include <CheckBoxKdeWidget.h>
#include <ButtonKdeWidget.h>
#include "KdeWidgetFactory.h"

KdeWidgetFactory::KdeWidgetFactory(int kdeVersion) {
    this->kdeVersion = kdeVersion;
}

std::shared_ptr<Widget> KdeWidgetFactory::create(std::string type) {
    if(type == "list")
        return std::make_shared<ListKdeWidget>(this->kdeVersion);
    if(type == "checkbox")
        return std::make_shared<CheckBoxKdeWidget>(this->kdeVersion);
    if(type == "button")
        return std::make_shared<ButtonKdeWidget>(this->kdeVersion);
}