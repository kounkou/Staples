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

class Staple 
{

/// public methods
public:
            Staple();
   virtual ~Staple();
            Staple(std::string _daysBeforeExpiration, std::string _stapleName, float _staplePrice, unsigned int _stapleQuantity);

   std::string  numberOfDaysBeforeExpiration() const;
   std::string  name() const;
   float        price() const;
   unsigned int quantity() const;

/// protected members
protected:
   std::string  _daysBeforeExpiration;
   std::string  _stapleName;
   float        _staplePrice;
   unsigned int _stapleQuantity;
};

#endif // end of _STAPLE_H_
