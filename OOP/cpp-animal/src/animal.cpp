#include "animal.h"

namespace go
{
    Animal::Animal(bool _mobile)
      : mobile(_mobile)
    {
    }
    
    void Animal::moving()
    {
        mobile = true;
    }
    
    void Animal::standing()
    {
        mobile = false;
    }

    bool Animal::isStarting() const
    {
        return mobile;
    }
    bool Animal::isMoving() const
    {
        return mobile;
    }
 }