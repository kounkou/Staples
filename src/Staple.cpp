
#include "Staple.h"

Staple::Staple()
   : _daysBeforeExpiration(0)
   , _stapleName("")
   , _staplePrice(0.0)
{
}

Staple::Staple(unsigned int _daysBeforeExpiration, std::string _stapleName, float _staplePrice)
    : _daysBeforeExpiration(_daysBeforeExpiration)
    , _stapleName(_stapleName)
    , _staplePrice(_staplePrice)
{
}

Staple::~Staple()
{
}

unsigned int Staple::numberOfDaysBeforeExpiration() const
{
   return _daysBeforeExpiration;
}

std::string  Staple::name() const
{
   return _stapleName;
}

float Staple::price() const
{
   return _staplePrice; 
}
