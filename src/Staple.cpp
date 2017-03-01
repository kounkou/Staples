
#include "Staple.h"

Staple::Staple()
   : _daysBeforeExpiration(0)
   , _stapleName("")
   , _staplePrice(0.0)
{
}

Staple::~Staple()
{
}

unsigned int Staple::getNumberOfDaysBeforeExpiration()
{
   return _daysBeforeExpiration;
}

std::string  Staple::getStapleName()
{
   return _stapleName;
}

float Staple::getStaplePrice()
{
   return _staplePrice; 
}
