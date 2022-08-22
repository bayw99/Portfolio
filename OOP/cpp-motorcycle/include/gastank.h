#pragma once

#include <stdexcept>

namespace go {

    class Gas {
        public: static const double TOTAL_MILES;
        public: static const double DEFAULT_TANK;
        public: static const double DEFAULT_GALLONS;
        public: const double tanksize; //dia
        private: double gallons; //pre
        private: bool miles;
        public: Gas(double _tanksize = DEFAULT_TANK, double _gallons = DEFAULT_GALLONS);
        
        public: double getTanksize() const;

        public: void setGallons(double value);

        public: double getGallons() const;

        public: bool isEmpty() const;

        public: bool hasMiles() const;

        public: void addGas(double additional);
    };
 }

