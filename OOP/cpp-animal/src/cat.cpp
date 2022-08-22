#include <stdexcept>
#include "cat.h"
namespace go
{
const double Cat::DEFAULT_ENERGY = 7.0;
Cat::Cat(double _agility)
    : Animal(false), health(2), energy(DEFAULT_ENERGY)
{
  health[ARMS] = std::shared_ptr<Health>(new Health(_agility));
  health[LEGS] = std::shared_ptr<Health>(new Health(_agility));
}

double Cat::getEnergy() const { return energy; }
void Cat::setEnergy(const double value)
{
  if (value < 0 || value > 1.0)
  {
    throw std::invalid_argument("invalid fuel amount");
  }
  energy = value;
}

Health &Cat::getArms() { return *health[ARMS]; }
const Health &Cat::getArms() const { return *health[ARMS]; }

Health &Cat::getLegs() { return *health[LEGS]; }
const Health &Cat::getLegs() const { return *health[LEGS]; }

bool Cat::isDead() const
{
  bool ans = false;
  for (auto health : health)
  {
    ans = ans || health->isDead();
  }
  return ans;
}

bool Cat::isMoving() const { return isStarting() && !isDead() && energy > 0.0; }

} // namespace go