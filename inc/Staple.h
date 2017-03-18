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
            Staple(unsigned int _daysBeforeExpiration, std::string _stapleName, float _staplePrice);

   unsigned int numberOfDaysBeforeExpiration() const;
   std::string  name() const;
   float        price() const;

/// protected members
protected:
   unsigned int _daysBeforeExpiration;
   std::string  _stapleName;
   float        _staplePrice;

};

#endif // end of _STAPLE_H_
