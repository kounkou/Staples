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
#include <QDate>

class Staple 
{

/// public methods
public:
            Staple();
   virtual ~Staple();
            Staple(QDate _expDate, std::string _stapleName, double _staplePrice, unsigned int _stapleQuantity);

   QDate        expirationDate() const;
   std::string  name()           const;
   double       price()          const;
   unsigned int quantity()       const;

/// protected members
protected:
   QDate        _expDate;
   std::string  _stapleName;
   double       _staplePrice;
   unsigned int _stapleQuantity;
};

#endif // end of _STAPLE_H_
