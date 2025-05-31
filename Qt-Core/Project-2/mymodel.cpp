#include "mymodel.hpp"

MyModel::MyModel(QObject *parent)
    : QAbstractListModel(parent)
{
    items_ = {
        {"Item A", 10},
        {"Item B", 20},
        {"Item C", 30}};
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(items_.size());
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= rowCount())
        return {};

    const auto &item = items_[index.row()];
    if (role == NameRole)
        return item.name;
    else if (role == ValueRole)
        return item.value;

    return {};
}

QHash<int, QByteArray> MyModel::roleNames() const
{
    return {
        {NameRole, "name"},
        {ValueRole, "value"}};
}
