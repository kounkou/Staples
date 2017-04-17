
#include "Staple.h"

Staple::Staple()
   : _expDate(QDateTime())
   , _stapleName("")
   , _staplePrice(0.0)
   , _stapleQuantity(0)
{
}

Staple::Staple(QDateTime _expirationDate, std::string _stapleName, double _staplePrice, unsigned int _stapleQuantity)
    : _expDate(_expirationDate)
    , _stapleName(_stapleName)
    , _staplePrice(_staplePrice)
    , _stapleQuantity(_stapleQuantity)
{
}

Staple::~Staple()
{
}

QDateTime Staple::expirationDate() const
{
   return _expDate;
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
