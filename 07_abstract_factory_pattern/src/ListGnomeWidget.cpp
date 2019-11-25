#include <ListGnomeWidget.h>

ListGnomeWidget::ListGnomeWidget(int gnomeVersion) {
    this->gnomeVersion = gnomeVersion;
}

void ListGnomeWidget::draw() {
    std::cout << "ListGnomeWidget\t" << this->gnomeVersion << std::endl;
}