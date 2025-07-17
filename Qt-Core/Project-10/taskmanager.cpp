#include "taskmanager.hpp"
#include <QFile>
#include <QTextStream>
#include <QDebug>

TaskManager::TaskManager(const QString& storageFile) : file(storageFile) {}

void TaskManager::startTask(const QString& name)
{
    if (activeTasks.contains(name))
    {
        qWarning() << "Task already running.";
        return;
    }
    activeTasks[name] = QDateTime::currentDateTime();
    qInfo() << "Started task:" << name;
}

void TaskManager::stopTask(const QString& name)
{
    if (!activeTasks.contains(name))
    {
        qWarning() << "Task not running.";
        return;
    }
    QDateTime start = activeTasks.take(name);
    qint64 duration = start.secsTo(QDateTime::currentDateTime());
    QFile f(file);
    if (f.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&f);
        out << name << "," << start.toString(Qt::ISODate) << ","
            << QDateTime::currentDateTime().toString(Qt::ISODate) << ","
            << duration << " sec\n";
        f.close();
    }
    qInfo() << "Stopped task:" << name << "Duration:" << duration << "seconds";
}

void TaskManager::listTasks() const
{
    QFile f(file);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "No tasks logged yet.";
        return;
    }
    QTextStream in(&f);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        qInfo().noquote() << line;
    }
    f.close();
}
