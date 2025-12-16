#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QString>
#include <QDateTime>
#include <QMap>

class TaskManager
{
  public:
    TaskManager(const QString& storageFile);

    void startTask(const QString& name);
    void stopTask(const QString& name);
    void listTasks() const;

  private:
    QString file;
    QMap<QString, QDateTime> activeTasks;
};

#endif // TASKMANAGER_H
