#include <QCoreApplication>
#include <QStateMachine>
#include <QState>
#include <QTimer>
#include <QDebug>

class Door : public QObject
{
    Q_OBJECT
public:
    QTimer toOpening, toOpen, toClosing, toClosed;

    Door()
    {
        toOpening.setSingleShot(true);
        toOpen.setSingleShot(true);
        toClosing.setSingleShot(true);
        toClosed.setSingleShot(true);
    }
};

int main(int argc, char *argv[])
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    /*
    for event loop (signals/slots, timers, asynchronous operations)
   */
    QCoreApplication app(argc, argv);

    Door door;

    QStateMachine machine;
    QState *closed = new QState();
    QState *opening = new QState();
    QState *open = new QState();
    QState *closing = new QState();

    int cycleCount = 0;

    // State behaviors
    QObject::connect(closed, &QState::entered, [&]()
                     {
        qDebug() << "Closed.";
        cycleCount++;
        if (cycleCount > 1) {
            QCoreApplication::quit();  // Exit after one full cycle
        } else {
            door.toOpening.start(1000);
        } });

    QObject::connect(opening, &QState::entered, [&]()
                     {
        qDebug() << "Opening...";
        door.toOpen.start(1000); });

    QObject::connect(open, &QState::entered, [&]()
                     {
        qDebug() << "Open!";
        door.toClosing.start(1000); });

    QObject::connect(closing, &QState::entered, [&]()
                     {
        qDebug() << "Closing...";
        door.toClosed.start(1000); });

    // Transitions
    closed->addTransition(&door.toOpening, &QTimer::timeout, opening);
    opening->addTransition(&door.toOpen, &QTimer::timeout, open);
    open->addTransition(&door.toClosing, &QTimer::timeout, closing);
    closing->addTransition(&door.toClosed, &QTimer::timeout, closed);

    // Setup
    machine.addState(closed);
    machine.addState(opening);
    machine.addState(open);
    machine.addState(closing);

    machine.setInitialState(closed);
    machine.start();

    return app.exec();
}

#include "main.moc"
