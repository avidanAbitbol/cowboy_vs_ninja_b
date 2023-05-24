//
// Created by avida on 5/15/2023.
//

#include "YoungNinja.hpp"

namespace ariel {

    YoungNinja::YoungNinja(const string &name, const Point &location) : Ninja(name, location) {
        this->setSpeed(14);
        this->setIsNinja(true);
        this->setHealth(100);
    }

} // ariel