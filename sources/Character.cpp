#include <limits>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Character.hpp"

namespace ariel {
    Character::Character(const std::string& name, const Point& location)
            : name(name), location(location), islive(true), inGroup(false), health(0) {}

    std::string Character::getName() const {
        return name;
    }

    void Character::setLocation(const Point location) {
        this->location = location;
    }

    const Point Character::getLocation() const {
        return location;
    }

    bool Character::isAlive() const {
        return islive;
    }

    double Character::distance(const Character* p) const {
        if (p == nullptr) {
            throw std::invalid_argument("Cannot compute distance to null Character");
        }
        return location.distance(p->getLocation());
    }

    void Character::hit(int damage) {
        if (damage < 0) {
            throw std::invalid_argument("Damage cannot be negative");
        }

        health -= damage;

        if (health <= 0) {
            islive = false;
        }
    }

    bool Character::getIsNinja() const {
        return isNinja;
    }

    void Character::setIsNinja(bool isNinja) {
        this->isNinja = isNinja;
    }

    Character* Character::findClosestCharacter(const std::vector<Character*>& team) const {
        Character* closestCharacter = nullptr;
        double closestDistance = std::numeric_limits<double>::max();

        for (const auto& character : team) {
            if (character != this && character->isAlive()) {
                double distance = character->distance(this);

                if (distance < closestDistance) {
                    closestDistance = distance;
                    closestCharacter = character;
                }
            }
        }

        return closestCharacter;
    }

    void Character::setHealth(int health) {
        this->health = health;
    }

    int Character::getHealth() const {
        return health;
    }

    void Character::setInGroup(bool inGroup) {
        this->inGroup = inGroup;
    }

    bool Character::getInGroup() const {
        return inGroup;
    }
} // ariel