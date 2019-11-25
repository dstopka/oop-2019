#include <ButtonKdeWidget.h>

ButtonKdeWidget::ButtonKdeWidget(int kdeVersion) {
    this->kdeVersion = kdeVersion;
}

void ButtonKdeWidget::draw() {
    std::cout << "ButtonKdeWidget\t" << this->kdeVersion << std::endl;
}