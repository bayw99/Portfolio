#pragma once

#include "animal.h"
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include "health.h"

namespace go
{

    class Dog : public Animal
    {
    private:
        std::vector<std::shared_ptr<Health>> health;
        std::string color;

    public:
        Dog(const std::string &_color, double _agility = Health::DEFAULT_AGILITY);
        const std::string &getColor() const;
        void setColor(const std::string &value);
        Health &getArms();
        const Health &getArms() const;
        Health &getLegs();
        const Health &getLegs() const;
        bool isDead() const;
        bool isMoving() const override;
};

typedef std::shared_ptr < Dog > DogPtr;

}