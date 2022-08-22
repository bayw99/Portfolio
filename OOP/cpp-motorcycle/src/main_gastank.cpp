#include "../include/gastank.h"
#include <stdexcept>

namespace go
{

const double Gas::TOTAL_MILES = 225;
const double Gas::DEFAULT_TANK = 4.5;
const double Gas::DEFAULT_GALLONS = 4.5;

Gas::Gas(double _tanksize, double _gallons)
    : tanksize(_tanksize), gallons(_gallons), miles(_gallons * 50 >= TOTAL_MILES)
{
    if (gallons < 0)
    {
        throw std::invalid_argument("gallons cannot be negative");
    }
}

double Gas::getTanksize() const
{
    return tanksize;
}

void Gas::setGallons(double value)
{
    if (value < 0.0)
    {
        throw std::invalid_argument("pressure cannot be negative");
    }
    if (value * 50 >= TOTAL_MILES)
    {
        miles = true;
    }
    if (miles)
    {
        value = 0.0;
    }
    gallons = value;
}

double Gas::getGallons() const
{
    return gallons;
}

bool Gas::isEmpty() const
{
    return gallons == 0.0;
}

bool Gas::hasMiles() const
{
    return miles;
}

void Gas::addGas(double additional)
{
    setGallons(getGallons() + additional);
}
} 

