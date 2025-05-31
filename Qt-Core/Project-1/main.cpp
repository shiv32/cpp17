#include <QCoreApplication>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    QCoreApplication app(argc, argv);

    QTimer::singleShot(1000, []()
                       {
        qDebug() << "Hello from Qt Core!";
        QCoreApplication::quit(); });

    return app.exec();
}
