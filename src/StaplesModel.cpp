
#include "StaplesModel.h"

StaplesModel* StaplesModel::_pInstance = NULL;

StaplesModel* StaplesModel::getInstance()
{
    if (!_pInstance)
    {
        _pInstance = new StaplesModel();
    }

    return _pInstance;
}

void StaplesModel::addStaple(unsigned int expirationDate, std::string name, float price)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    _staplesContainer.push_back(Staple(expirationDate, name, price));
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

    if (role == NameRole)           { return QString::fromStdString(staple.name()); }
    if (role == ExpirationDateRole) { return staple.numberOfDaysBeforeExpiration(); }
    if (role == PriceRole)          { return staple.price(); }

    return QVariant();
}


