#include <stdexcept>
#include "dog.h"

namespace go
{

    Dog::Dog(const std::string &_color, double _agility)
        : Animal(false), color(_color), health(2)
    {
        health[0] = std::shared_ptr<Health>(new Health(_agility));
        health[1] = std::shared_ptr<Health>(new Health(_agility));
    }

    const std::string &Dog::getColor() const
    {
        return color;
    }
    void Dog::setColor(const std::string &value)
    {
        color = value;
    }

    Health &Dog::getArms()
    {
        return *health[0];
    }

    const Health &Dog::getArms() const
    {
        return *health[0];
    }

    Health &Dog::getLegs()
    {
        return *health[1];
    }

    const Health &Dog::getLegs() const
    {
        return *health[1];
    }

    bool Dog::isDead() const
    {
        return getArms().isDead() || getLegs().isDead(); }

    bool Dog::isMoving() const
    {
        return isMoving() && !isDead();
    }

}


