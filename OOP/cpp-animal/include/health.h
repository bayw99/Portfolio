#pragma once

#include <stdexcept>

namespace go
{

    class Health
    {
        public:
            static const double BAD_STRENGTH; //pres
            static const double DEFAULT_AGILITY; //ddia
            static const double DEFAULT_STRENGTH; //dpres
            const double agility;
        private:
            double strength;
            bool bad;
        public: Health(double _agility = DEFAULT_AGILITY, double _strength = DEFAULT_STRENGTH);
            double getAgility() const;
            void setStrength(double value);
            double getStrength() const;
            bool isDead() const;
            bool hasBad() const;
            void food(double additional); //inflate
    };
 }