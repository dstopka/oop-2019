#include <ButtonGnomeWidget.h>

ButtonGnomeWidget::ButtonGnomeWidget(int gnomeVersion) {
    this->gnomeVersion = gnomeVersion;
}

void ButtonGnomeWidget::draw() {
    std::cout << "ButtonGnomeWidget\t" << this->gnomeVersion << std::endl;
}