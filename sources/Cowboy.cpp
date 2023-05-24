//
// Created by avida on 5/15/2023.
//
#include <stdexcept>

#include "Cowboy.hpp"

namespace ariel {
    Cowboy::Cowboy(const string &name, const Point &location) : Character(name, location) {
        setIsNinja(false) ;
        bullets = 6;
        setHealth(110);
    }
    string Cowboy::print(){
        if(!isAlive()){
            return "X"+getName()+" is dead";
        }
        return "C"+getName()+ "-" + to_string(getHealth() ) + " is at "+getLocation().print();
    }
    bool Cowboy::hasboolets(){
        return bullets > 0;
    }
    void Cowboy::shoot(Character *wasShot) {
        if (this == wasShot) {
            throw std::runtime_error("you can't shoot yourself");
        }
        if (!wasShot->isAlive()) {
            throw std::runtime_error("the character is dead");
        }
        if (!this->isAlive()) {
            throw std::runtime_error("you can't shoot if you are dead");
        }
        if (hasboolets()) {
            bullets--;
            wasShot->hit(10);
        } else {
            reload();
        }
    }

    void Cowboy::reload() {
        if (!this->isAlive()) {
            throw std::runtime_error("you can't reload if you are dead");
        }
        bullets = 6;
    }
    void Cowboy::damage(Character *character) {
        if (!isAlive()) {
            return;
        }
        if (character != nullptr && character->isAlive()) {
            shoot(character);
        }
    }


} // ariel