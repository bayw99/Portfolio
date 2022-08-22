#pragma once

#include <memory>

namespace go
{
    class Animal
    {
    private: bool mobile;
    public: Animal(bool _mobile = false);
    public: virtual void moving();
    public: virtual void standing();
    public: virtual bool isStarting() const;
    public: virtual bool isMoving() const;
    };
    typedef std::shared_ptr < Animal > AnimalPtr;
}