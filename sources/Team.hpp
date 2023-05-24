//
// Created by avida on 5/15/2023.
//
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
#include <vector>
#include <string>

#ifndef COWBOY_VS_NINJA_A_TEAM_H
#define COWBOY_VS_NINJA_A_TEAM_H

namespace ariel {

    class Team {
        Character *leader;
    public:
        std::vector<Character*> team;
        Team(Character *leader);// constructor
        virtual void add(Character *c);
        int stillAlive()const;
        virtual void attack(Team *c);
        void print();
        virtual ~Team();
        Character* getLeader() const;
        void setLeader(Character *leader);
    };

}; // ariel

#endif //COWBOY_VS_NINJA_A_TEAM_H
