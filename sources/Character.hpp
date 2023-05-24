//
// Created by avida on 5/15/2023.
//
#include "Point.hpp"
#include <vector>
#include <string>
#ifndef COWBOY_VS_NINJA_A_CHARACTER_H
#define COWBOY_VS_NINJA_A_CHARACTER_H

namespace ariel {

    class Character {
        Point location ;
    bool islive;
    string name;
    int health;
    bool isNinja;
    bool inGroup;
    public:
        Character(const string &name, const Point &location);
        string getName() const;
        void setLocation(Point location);
        const Point getLocation() const;
        bool isAlive()const;
        double distance(const Character *p) const;
        void hit(int damage);
        virtual string print()=0;
        virtual ~Character()=default;
        bool getIsNinja() const;
        void setIsNinja(bool isNinja);
        Character* findClosestCharacter(const std::vector<Character*>&team) const;
        virtual void damage(Character* enemy)=0;
        void setHealth(int health);
        int getHealth() const;
        void setInGroup(bool inGroup);
        bool getInGroup() const;
    };

} // ariel

#endif //COWBOY_VS_NINJA_A_CHARACTER_H
