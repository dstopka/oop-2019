#include <CheckBoxGnomeWidget.h>

CheckBoxGnomeWidget::CheckBoxGnomeWidget(int gnomeVersion) {
    this->gnomeVersion = gnomeVersion;
}

void CheckBoxGnomeWidget::draw() {
    std::cout << "CheckBoxGnomeWidget\t" << this->gnomeVersion << std::endl;
}