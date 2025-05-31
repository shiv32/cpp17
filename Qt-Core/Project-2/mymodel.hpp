#pragma once
#include <QAbstractListModel>
#include <QString>
#include <vector>

struct Item
{
    QString name;
    int value;
};

class MyModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles
    {
        NameRole = Qt::UserRole + 1,
        ValueRole
    };

    explicit MyModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    std::vector<Item> items_;
};
