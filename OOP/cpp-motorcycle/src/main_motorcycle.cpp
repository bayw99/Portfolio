#include <stdexcept>
#include "../include/motorcycle.h"
namespace go
{

  Motorcycle::Motorcycle(const std::string &_color, double _tanksize)
    : color(_color), tanksize(1), started(false)
  {
    tanksize[0]=std::shared_ptr<Gas>(new Gas(_tanksize));
  }

  const std::string &Motorcycle::getColor() const { return color; }
  void Motorcycle::setColor(const std::string &value) { color = value; }

  Motorcycle& Motorcycle::getTank() { return *tanksize[0]; }
  const Motorcycle& Motorcycle::getTank() const { return *tanksize[0]; }

  bool Motorcycle::isEmpty() const { return getTank().isEmpty(); }

  void Motorcycle::start() { started = true; }
  void Motorcycle::stop() { started = false; }

  bool Motorcycle::isStarted() const { return started; }
  bool Motorcycle::isGoing() const { return isStarted() && ! isEmpty(); }

} // namespace go

