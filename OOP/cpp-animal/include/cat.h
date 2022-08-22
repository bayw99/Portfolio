#pragma once

#include "animal.h"

#include <vector>
#include <memory>
#include "health.h"

namespace go
{

class Cat : public Animal
{

public:
    static const double DEFAULT_ENERGY;
    enum LIMBS_INDEX
    {
        ARMS,
        LEGS
    };

private:
    std::vector<std::shared_ptr<Health>> health;

private:
    double energy;

public:
    Cat(double _agility = Health::DEFAULT_AGILITY);

public:
    double getEnergy() const;

public:
    void setEnergy(double value);

public:
    Health &getArms();

public:
    const Health &getArms() const;

public:
    Health &getLegs();

public:
    const Health &getLegs() const;

public:
    bool isDead() const;

public:
    bool isMoving() const override;
};

typedef std::shared_ptr < Cat > CatPtr;

} // namespace go