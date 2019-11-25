#include <Demo.h>
#include <KdeWidgetFactory.h>
#include <GnomeWidgetFactory.h>

int main() {

    auto demo1 = Demo(std::make_shared<KdeWidgetFactory>(1));
    auto demo2 = Demo(std::make_shared<GnomeWidgetFactory>(100));

    demo1.run("list");
    demo1.run("button");
    demo1.run("checkbox");

    demo2.run("list");
    demo2.run("button");
    demo2.run("checkbox");

    return 0;
}