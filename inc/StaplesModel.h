
#ifndef _STAPLES_MODEL_H_
#define _STAPLES_MODEL_H_

#include <QAbstractListModel>
#include <QObject>
#include "Staple.h"

enum StaplesRoles
{
   ExpirationDateRole = Qt::UserRole + 1,
   NameRole           = Qt::UserRole + 2,
   PriceRole          = Qt::UserRole + 3,
   QuantityRole       = Qt::UserRole + 4
};

class StaplesModel : public QAbstractListModel 
{
   Q_OBJECT

public slots:
   void addStaple(unsigned int expirationDate,
                  std::string  name,
                  float        price,
                  unsigned int quantity);
public:
   StaplesModel(QObject* parent = 0);
  ~StaplesModel();

   static StaplesModel* getInstance();
   int staplesContainerSize() const;

   int      rowCount(const QModelIndex& parent = QModelIndex())        const;
   QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
   
protected:
   QHash<int, QByteArray> roleNames() const;
   QHash<int, QByteArray> roleIds()   const;

private:
   std::vector<Staple>  _staplesContainer;
   static StaplesModel* _pInstance;
};

#endif
