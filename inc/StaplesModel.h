
#ifndef _STAPLES_MODEL_H_
#define _STAPLES_MODEL_H_

#include <QAbstractListModel>
#include <QObject>
#include "Staple.h"

enum StaplesRoles
{
   ExpirationDateRole = Qt::UserRole + 1,
   NameRole           = Qt::UserRole + 2,
   PriceRole          = Qt::UserRole + 3
};

class StaplesModel : public QAbstractListModel 
{
   Q_OBJECT

public slots:
   void addStaple(unsigned int expirationDate,
                  std::string  name,
                  float        price);
public:
   StaplesModel(QObject* parent = 0);
  ~StaplesModel();

   int      rowCount(const QModelIndex& parent = QModelIndex())        const;
   QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
   
protected:
   QHash<int, QByteArray> roleExpirationDate() const;
   QHash<int, QByteArray> roleNames()          const;
   QHash<int, QByteArray> rolePrice()          const;

private:
   std::vector<Staple> _staplesContainer;
};

#endif
