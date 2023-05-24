//
// Created by avida on 5/15/2023.
//

#include "OldNinja.hpp"

namespace ariel {


OldNinja::OldNinja(const string &name, const Point &location):Ninja(name, location) {
    this->setSpeed(8);
    this->setIsNinja(true);
    this->setHealth(150);
}
} // ariel