#pragma once

#include <vector>
#include <memory>
#include "gastank.h"

namespace go {

    class Motorcycle {
    private: std::vector < std::shared_ptr < Gas > > gas;
    private: std::string color;
    private: bool started;

    public: Motorcycle(const std::string &_color, double _tanksize = Gas::DEFAULT_TANK);

    public: const std::string &getColor() const;
    public: void setColor(const std::string &value);

    public:  Gas& getTank();
    public:  const Gas& getTank() const;

    public: bool isEmpty() const;

    public: void start();
    public: void stop();

    public: bool isStarted() const;
    public: bool isGoing() const;
    };
 }

