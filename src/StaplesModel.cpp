
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

int StaplesModel::displayListOfStaples() const
{
    int status = 1;
    QList<Staple>::const_iterator it  = _staplesContainer.begin();

    if (it == _staplesContainer.end())
    {
        status = 1;
    }
    else
    {
        status = 0;
        for (; it != _staplesContainer.end(); ++it)
        {
            qDebug() << "Staples list contains : " << QString::fromStdString((*it).name());
        }
    }

    return status;
}

/*
 * clearing list of staples implies
 * more than just removing the elements for the container.
 * In reality, this implies also sending
 * signals to the view (qml)
 * This is done using the bening and EndRemovingRows
 */
void StaplesModel::clearListOfStaples()
{
    beginRemoveRows(QModelIndex(), 0, rowCount());
    for (int row = 0; row < rowCount(); ++row)
    {
        _staplesContainer.removeAt(row);
        _staplesContainer.erase(_staplesContainer.begin(),
                                _staplesContainer.end());
    }
    endRemoveRows();
}

/*
 * addStaple will add a staple inside the container
 * This function is made with insert
 * instead and in place of push_back
 * Using insert will garanty the object doesn't call
 * the copy constructor again.
 */
void StaplesModel::addStaple(QDateTime expirationDate, std::string name, double price, unsigned int quantity)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    _staplesContainer.insert(0, Staple(expirationDate, name, price, quantity));
    qDebug() << "new staples size : " << _staplesContainer.count();
    endInsertRows();
}

StaplesModel::StaplesModel(QObject *parent)
    : QAbstractListModel(parent)
    , _staplesContainer(QList<Staple>())
{
}

int StaplesModel::staplesContainerSize() const
{
    return _staplesContainer.count();
}

QHash<int, QByteArray> StaplesModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[ExpirationDateRole] = "expirationDate";
    roles[NameRole]           = "name";
    roles[PriceRole]          = "price";
    roles[QuantityRole]       = "quantity";

    return roles;
}

int StaplesModel::rowCount(const QModelIndex &) const
{
    return _staplesContainer.count();
}

QVariant StaplesModel::data(const QModelIndex &index, int role) const
{
    const Staple& staple = _staplesContainer[index.row()];

    if (index.row() < 0 || index.row() > _staplesContainer.count())
    {
        return QVariant();
    }

    if (role == NameRole)           { return QString::fromStdString(staple.name()); }
    if (role == ExpirationDateRole) { return staple.expirationDate().toString(); }
    if (role == PriceRole)          { return staple.price(); }
    if (role == QuantityRole)       { return staple.quantity(); }

    return QVariant();
}

StaplesModel::~StaplesModel()
{
}
