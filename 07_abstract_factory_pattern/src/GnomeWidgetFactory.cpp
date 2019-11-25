#include <ListGnomeWidget.h>
#include <CheckBoxGnomeWidget.h>
#include <ButtonGnomeWidget.h>
#include "GnomeWidgetFactory.h"

GnomeWidgetFactory::GnomeWidgetFactory(int gnomeVersion) {
    this->gnomeVersion = gnomeVersion;
}

std::shared_ptr<Widget> GnomeWidgetFactory::create(std::string type) {
    if(type == "list")
        return std::make_shared<ListGnomeWidget>(this->gnomeVersion);
    if(type == "checkbox")
        return std::make_shared<CheckBoxGnomeWidget>(this->gnomeVersion);
    if(type == "button")
        return std::make_shared<ButtonGnomeWidget>(this->gnomeVersion);
}