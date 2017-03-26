
#include "Staple.h"

Staple::Staple()
   : _daysBeforeExpiration("")
   , _stapleName("")
   , _staplePrice(0.0)
   , _stapleQuantity(0)
{
}

Staple::Staple(std::string _daysBeforeExpiration, std::string _stapleName, float _staplePrice, unsigned int _stapleQuantity)
    : _daysBeforeExpiration(_daysBeforeExpiration)
    , _stapleName(_stapleName)
    , _staplePrice(_staplePrice)
    , _stapleQuantity(_stapleQuantity)
{
}

Staple::~Staple()
{
}

std::string Staple::numberOfDaysBeforeExpiration() const
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

unsigned int Staple::quantity() const
{
    return _stapleQuantity;
}
