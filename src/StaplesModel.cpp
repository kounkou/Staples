
#include "StaplesModel.h"

void StaplesModel::addStaple(unsigned int expirationDate, std::string name, float price)
{
    Staple tmpStaple(expirationDate, name, price);

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    _staplesContainer.push_back(tmpStaple);
    endInsertRows();
}

StaplesModel::StaplesModel(QObject *parent) : QAbstractListModel(parent)
{
}

StaplesModel::~StaplesModel()
{
}

QHash<int, QByteArray> StaplesModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[NameRole]           = "name";
    roles[ExpirationDateRole] = "numberOfDaysBeforeExpiration";
    roles[PriceRole]          = "price";

    return roles;
}

int StaplesModel::rowCount(const QModelIndex &) const
{
    return _staplesContainer.size();
}

QVariant StaplesModel::data(const QModelIndex &index, int role) const
{
    const Staple& staple = _staplesContainer[index.row()];

    if (index.row() < 0 || index.row() > _staplesContainer.size())
    {
        return QVariant();
    }

    if      (role == NameRole)           { return QString::fromStdString(staple.name()); }
    else if (role == ExpirationDateRole) { return staple.numberOfDaysBeforeExpiration(); }
    else if (role == PriceRole)          { return staple.price(); }

    return QVariant();
}


