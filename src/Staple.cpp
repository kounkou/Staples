
#include "Staple.h"

Staple::Staple()
   : _daysBeforeExpiration("")
   , _stapleName("")
   , _staplePrice(0.0)
   , _stapleQuantity(0)
{
}

Staple::Staple(std::string _daysBeforeExpiration, std::string _stapleName, double _staplePrice, unsigned int _stapleQuantity)
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

double Staple::price() const
{
   return _staplePrice; 
}

unsigned int Staple::quantity() const
{
    return _stapleQuantity;
}
