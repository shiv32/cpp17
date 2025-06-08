#include <QCoreApplication>
#include <QAbstractTableModel>
#include <QString>
#include <QVector>
#include <QTextStream>

struct Contact
{
    QString name;
    QString phone;
};

class ContactTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ContactTableModel(QObject *parent = nullptr)
        : QAbstractTableModel(parent) {}

    void addContact(const Contact &contact)
    {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_contacts.append(contact);
        endInsertRows();
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override
    {
        Q_UNUSED(parent);
        return m_contacts.size();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override
    {
        Q_UNUSED(parent);
        return 2; // Name and Phone
    }

    QVariant data(const QModelIndex &index, int role) const override
    {
        if (!index.isValid() || index.row() >= m_contacts.size())
            return QVariant();

        if (role == Qt::DisplayRole)
        {
            const Contact &c = m_contacts[index.row()];

            if (index.column() == 0)
                return c.name;
            else if (index.column() == 1)
                return c.phone;

        }
        
        return QVariant();
    }

    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override
    {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
        {
            if (section == 0)
                return QString("Name");
            else if (section == 1)
                return QString("Phone");
        }
        return QVariant();
    }

private:
    QVector<Contact> m_contacts;
};

int main(int argc, char *argv[])
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    /*
     for event loop (signals/slots, timers, asynchronous operations)
    */
    // QCoreApplication app(argc, argv);

    ContactTableModel model;

    model.addContact({"Alice", "+91-9999999999"});
    model.addContact({"Bob", "+91-8888888888"});
    model.addContact({"Charlie", "+91-7777777777"});

    QTextStream out(stdout);
    out << "Contacts Table:\n---------------------------\n";

    // Print headers
    out << model.headerData(0, Qt::Horizontal).toString() << "\t"
        << model.headerData(1, Qt::Horizontal).toString() << "\n";

    // Print all rows
    for (int row = 0; row < model.rowCount(); ++row)
    {
        for (int col = 0; col < model.columnCount(); ++col)
        {
            QModelIndex idx = model.index(row, col);
            out << model.data(idx, Qt::DisplayRole).toString() << "\t";
        }
        
        out << "\n";
    }

    return 0;
}

#include "main.moc"
