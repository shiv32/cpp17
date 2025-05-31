#include <QCoreApplication>
#include <QDebug>
#include "mymodel.hpp"

int main(int argc, char *argv[])
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    QCoreApplication app(argc, argv);

    MyModel model;

    for (int i = 0; i < model.rowCount(); ++i)
    {
        qDebug() << model.data(model.index(i), MyModel::NameRole).toString()
                 << model.data(model.index(i), MyModel::ValueRole).toInt();
    }

    return 0;
}
