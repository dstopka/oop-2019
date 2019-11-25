#include "Demo.h"

#include <utility>

Demo::Demo(std::shared_ptr<WidgetFactory> factory) : factory(std::move(factory)) {}


void Demo::run(std::string type) {
    auto widget = this->factory->create(type);
    widget->draw();
}