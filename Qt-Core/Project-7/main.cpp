#include <QCoreApplication>
#include <QObject>
#include <QDebug>

class MyObject : public QObject
{
    Q_OBJECT

public:
    MyObject(QObject *parent = nullptr) : QObject(parent) {}

signals:
    void mySignal();

public slots:
    void mySlot()
    {
        qDebug() << "shiv Slot called!";
    }

    void emitSignal()
    {
        emit mySignal();
    }
};

int main(int argc, char *argv[])
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    /*
     for event loop (signals/slots, timers, asynchronous operations)
    */
    // QCoreApplication app(argc, argv);

    MyObject obj;

    QObject::connect(&obj, &MyObject::mySignal, &obj, &MyObject::mySlot);

    obj.emitSignal();

    return 0;
}

#include "main.moc" // Required for Qt to include MOC-generated code
