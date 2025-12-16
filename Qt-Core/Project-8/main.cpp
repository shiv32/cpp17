#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QCoreApplication::setApplicationName("Qt5CLIApp");
    QCoreApplication::setApplicationVersion("1.0");
    QCommandLineParser parser;

    parser.setApplicationDescription("Qt 5.15.2 CLI Example");
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption nameOption({"n", "name"}, "Your name", "name");

    parser.addOption(nameOption);
    parser.process(app);

    QString name = parser.value(nameOption);
    qInfo() << "Hello," << (name.isEmpty() ? "Qt User" : name);
    
    return 0;
}
