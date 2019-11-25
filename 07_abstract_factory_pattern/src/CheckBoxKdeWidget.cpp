#include "CheckBoxKdeWidget.h"

CheckBoxKdeWidget::CheckBoxKdeWidget(int kdeVersion) {
    this->kdeVersion = kdeVersion;
}

void CheckBoxKdeWidget::draw() {
    std::cout << "CheckBoxKdeWidget\t" << this->kdeVersion << std::endl;
}