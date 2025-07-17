#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include "taskmanager.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QCoreApplication::setApplicationName("TaskTimer");
    QCoreApplication::setApplicationVersion("1.0");
    QCommandLineParser parser;

    parser.setApplicationDescription("Command-line Task Timer using Qt 5");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("command", "start | stop | list");
    parser.addPositionalArgument("taskname", "Name of the task (if applicable).");
    parser.process(app);

    const QStringList args = parser.positionalArguments();
    TaskManager manager("tasklog.txt");

    if (args.isEmpty())
    {
        qCritical() << "No command given. Use start, stop or list.";
        return 1;
    }

    const QString command = args[0];

    if (command == "start" && args.size() > 1)
    {
        manager.startTask(args[1]);
    }
    else if (command == "stop" && args.size() > 1)
    {
        manager.stopTask(args[1]);
    }
    else if (command == "list")
    {
        manager.listTasks();
    }
    else
    {
        qCritical() << "Invalid command or missing task name.";
        return 1;
    }
    
    return 0;
}
