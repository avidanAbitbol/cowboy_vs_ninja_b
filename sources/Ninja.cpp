//
// Created by avida on 5/15/2023.
//
#include <stdexcept>

#include "Ninja.hpp"

namespace ariel {
    Ninja::Ninja(const string &name, const Point &location) : Character(name, location) {
        setIsNinja(true);
    }

    void Ninja::move(const Character *player){
        this->setLocation(this->getLocation().moveTowards(player->getLocation(),speed));
    }
    void Ninja::slash(Character *someCharacter) {
        if (this == someCharacter) {
            throw std::runtime_error("you can't hit yourself");
        }
        if (!someCharacter->isAlive()) {
            throw std::runtime_error("you can't hit a dead character");
        }
        if (!this->isAlive()) {
            throw std::runtime_error("you can't hit if you are dead");
        }
        if (this->distance(someCharacter) <= 1) {
            someCharacter->hit(40);
        }
    }
    string Ninja::print(){
    return "Ninja "+this->getName()+" "+ to_string(getHealth()) +" is at "+this->getLocation().print();
    }
    void Ninja::setSpeed(int speed){
        this->speed=speed;
    }
    const int Ninja::getSpeed()const{
        return speed;
    }
    void Ninja::damage(Character *character) {
        if (!isAlive()) {
            return;
        }
        if (character != nullptr && character->isAlive()) {
            if(this->distance(character)<=1){
                this->slash(character);
            }
            else{
                this->move(character);
            }
        }
    }
} // ariel