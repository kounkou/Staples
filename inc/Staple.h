/*
 *
 * FILE : Staple.h
 *
 * DESCRIPTION
 * Staple is a unitary element to included inside
 * a container of houseold staples
 */

#ifndef _STAPLE_H_
#define _STAPLE_H_

#include <string>
#include <QDateTime>

class Staple 
{

/// public methods
public:
            Staple();
   virtual ~Staple();
            Staple(QDateTime _expDate, std::string _stapleName, double _staplePrice, unsigned int _stapleQuantity);

   QDateTime    expirationDate() const;
   std::string  name()           const;
   double       price()          const;
   unsigned int quantity()       const;

/// protected members
protected:
   QDateTime    _expDate;
   std::string  _stapleName;
   double       _staplePrice;
   unsigned int _stapleQuantity;
};

#endif // end of _STAPLE_H_
