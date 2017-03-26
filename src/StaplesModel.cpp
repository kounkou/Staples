
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

void StaplesModel::addStaple(std::string expirationDate, std::string name, float price, unsigned int quantity)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    _staplesContainer.push_back(Staple(expirationDate, name, price, quantity));
    endInsertRows();
}

StaplesModel::StaplesModel(QObject *parent)
    : QAbstractListModel(parent)
    , _staplesContainer(std::vector<Staple>())
{
}

StaplesModel::~StaplesModel()
{
}

int StaplesModel::staplesContainerSize() const
{
    return _staplesContainer.size();
}

QHash<int, QByteArray> StaplesModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[NameRole]           = "name";
    roles[ExpirationDateRole] = "numberOfDaysBeforeExpiration";
    roles[PriceRole]          = "price";
    roles[QuantityRole]       = "quantity";

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
    if (role == ExpirationDateRole) { return QString::fromStdString(staple.numberOfDaysBeforeExpiration()); }
    if (role == PriceRole)          { return staple.price(); }
    if (role == QuantityRole)       { return staple.quantity(); }

    return QVariant();
}


