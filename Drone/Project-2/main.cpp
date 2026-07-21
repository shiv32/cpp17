#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "backend/Drone.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Drone drone;

    engine.rootContext()->setContextProperty("drone", &drone);

    engine.load(QUrl("qrc:/Main.qml"));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
