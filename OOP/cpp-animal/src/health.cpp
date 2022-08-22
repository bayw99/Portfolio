#include <stdexcept>
#include "health.h"

namespace go
{

    const double Health::BAD_STRENGTH = 2.0;
    const double Health::DEFAULT_AGILITY = 6.0; //dia
    const double Health::DEFAULT_STRENGTH = 8.0; //pres

    Health::Health(double _agility, double _strength)
        : agility(_agility), strength(_strength), bad(_strength >= BAD_STRENGTH)
    {
        if (strength < 0)
        {
            throw std::invalid_argument("strength cannot be negative");
        }
    }

    double Health::getAgility() const
    {
        return agility;
    }

    void Health::setStrength(double value)
    {
        if (value < 0.0)
        {
            throw std::invalid_argument("strength cannot be negative");
        }
        if (value <= BAD_STRENGTH)
        {
            bad = true;
        }
        strength = value;
    }

    double Health::getStrength() const
    {
        return strength;
    }

    bool Health::isDead() const
    {
        return strength == 0.0;
    }

    bool Health::hasBad() const
    {
        return bad;
    }

    void Health::food(double additional)
    {
        setStrength(getStrength() + additional);
    }
}

