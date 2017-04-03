
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

void StaplesModel::clearListOfStaples()
{
}

/*
 * addStaple will add a staple inside the container
 * This function is made with insert
 * instead and in place of push_back
 * Using insert will garanty the object doesn't call
 * the copy constructor again.
 */
void StaplesModel::addStaple(std::string expirationDate, std::string name, float price, unsigned int quantity)
{
    std::vector<Staple>::iterator it = _staplesContainer.begin();
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    _staplesContainer.insert(it, Staple(expirationDate, name, price, quantity));
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


