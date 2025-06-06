#include <QCoreApplication>
#include <QSortFilterProxyModel>
#include <QStringListModel>
#include <QDebug>

class StartsWithAFilter : public QSortFilterProxyModel
{
protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override
    {
        QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
        QString data = sourceModel()->data(index).toString();
        return data.startsWith("A", Qt::CaseInsensitive);
    }
};

int main(int argc, char *argv[])
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

     /*
     for event loop (signals/slots, timers, asynchronous operations)
    */
    // QCoreApplication app(argc, argv);

    // Source model
    QStringList items = {"Banana", "Apple", "Avocado", "Grapes", "Apricot"};
    auto *sourceModel = new QStringListModel(items);

    // Proxy model with custom filter
    auto *proxyModel = new StartsWithAFilter();
    proxyModel->setSourceModel(sourceModel);
    proxyModel->sort(0); // Sort alphabetically

    qDebug() << "Filtered & Sorted Output (Starts with 'A'):";

    for (int row = 0; row < proxyModel->rowCount(); ++row)
    {
        QModelIndex index = proxyModel->index(row, 0);

        qDebug() << proxyModel->data(index).toString();
    }

    return 0;
}
