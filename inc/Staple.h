
#ifndef _STAPLE_H_
#define _STAPLE_H_

#include <string>

class Staple 
{

/// public methods
public:
   Staple();
   virtual ~Staple(); 

   unsigned int getNumberOfDaysBeforeExpiration();
   std::string  getStapleName();
   float        getStaplePrice();

protected:
   unsigned int _daysBeforeExpiration;
   std::string  _stapleName;
   float        _staplePrice;
};

#endif // end of _STAPLE_H_
