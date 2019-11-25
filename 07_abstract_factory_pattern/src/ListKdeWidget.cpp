#include <ListKdeWidget.h>

ListKdeWidget::ListKdeWidget(int kdeVersion) {
    this->kdeVersion = kdeVersion;
}

void ListKdeWidget::draw() {
    std::cout << "ListKdeWidget\t" << this->kdeVersion << std::endl;
}