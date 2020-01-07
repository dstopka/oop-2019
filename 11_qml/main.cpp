#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "acceleration.h"
#include "speed.h"
#include "displacement.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    qmlRegisterType<Displacement>("Observer.Pattern", 1, 0, "Displacement");
    qmlRegisterType<Speed>("Observer.Pattern", 1, 0, "Speed");
    qmlRegisterType<Acceleration>("Observer.Pattern", 1, 0, "Acceleration");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
