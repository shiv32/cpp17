#include <QCoreApplication>
#include <QAbstractTableModel>
#include <QSortFilterProxyModel>
#include <QDebug>
#include <vector>

struct Contact
{
    QString name;
    QString phone;
};

class ContactModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ContactModel(QObject *parent = nullptr)
        : QAbstractTableModel(parent)
    {
        contacts = {
            {"Alice", "123"},
            {"Bob", "456"},
            {"Charlie", "789"},
            {"Daniel", "000"},
            {"Diana", "999"}};
    }

    int rowCount(const QModelIndex &) const override
    {
        return static_cast<int>(contacts.size());
    }

    int columnCount(const QModelIndex &) const override
    {
        return 2;
    }

    QVariant data(const QModelIndex &index, int role) const override
    {

        if (!index.isValid() || role != Qt::DisplayRole)
            return {};

        const auto &contact = contacts.at(index.row());

        return index.column() == 0 ? contact.name : contact.phone;
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override
    {

        if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        {
            return section == 0 ? "Name" : "Phone";
        }

        return {};
    }

private:
    std::vector<Contact> contacts;
};

class NameFilterProxy : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    void setFilterString(const QString &str)
    {
        filterString = str;
        invalidateFilter();
    }

protected:
    bool filterAcceptsRow(int row, const QModelIndex &parent) const override
    {
        QModelIndex index = sourceModel()->index(row, 0, parent); // Column 0 = Name
        QString name = sourceModel()->data(index).toString();
        return name.contains(filterString, Qt::CaseInsensitive);
    }

private:
    QString filterString;
};

int main(int argc, char *argv[])
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    /*
     for event loop (signals/slots, timers, asynchronous operations)
    */
    // QCoreApplication app(argc, argv);

    ContactModel model;
    NameFilterProxy proxy;
    proxy.setSourceModel(&model);
    proxy.setFilterString("an"); // Will match "Daniel" and "Diana"
    proxy.sort(0);               // Sort by name

    qDebug() << "Filtered & Sorted Contacts (name contains 'an'):";

    for (int row = 0; row < proxy.rowCount(); ++row)
    {
        QString name = proxy.data(proxy.index(row, 0)).toString();
        QString phone = proxy.data(proxy.index(row, 1)).toString();
        qDebug() << name << "|" << phone;
    }

    return 0;
}

#include "main.moc"
