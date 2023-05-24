
#include "Team.hpp"
#include <stdexcept>
#include <algorithm>

namespace ariel {
    Team::Team(Character *leader) {
        if (leader == nullptr) {
            throw std::runtime_error("The leader is null");
        }
        if (leader->getInGroup()) {
            throw std::runtime_error("The leader is already in a team");
        }
        this->leader = leader;
        team.push_back(leader);
        leader->setInGroup(true);
    }

    void Team::add(Character *character) {
        if (character == nullptr) {
            throw std::runtime_error("The character is null");
        }

        if (character->getInGroup()) {
            throw std::runtime_error("The character is already in a team");
        }

        if (team.size() >= 10) {
            throw std::runtime_error("The team is full");
        }

        character->setInGroup(true);
        team.push_back(character);

        std::sort(team.begin(), team.end(), [](Character *a, Character *b) {
            if (a->getIsNinja() && !b->getIsNinja()) {
                return true;
            }
            if (!a->getIsNinja() && b->getIsNinja()) {
                return false;
            }
            return a->getIsNinja() && b->getIsNinja();
        });
    }

    int Team::stillAlive() const {
        int count = 0;
        for (const auto &character: team) {
            if (character->isAlive()) {
                count++;
            }
        }
        return count;
    }

    void Team::attack(Team *enemyTeam) {
        if (enemyTeam == nullptr) {
            throw std::invalid_argument("Cannot attack a null team");
        }
        if(!enemyTeam->stillAlive()){
            throw std::runtime_error("The enemy team is dead");
        }
        if (!stillAlive() || !enemyTeam->stillAlive()) {
            return; // Return if either team is dead
        }
        if(!this->leader->isAlive()){
            this->setLeader(this->leader->findClosestCharacter(this->team));// No team members left alive
        }
        Character *closestEnemy = nullptr;
        closestEnemy=this->leader->findClosestCharacter(enemyTeam->team);
        if(closestEnemy== nullptr){
            return;// No team members left alive
        }
        for(auto &character:team){
            if(character->isAlive()){
                if(!closestEnemy->isAlive()){
                    closestEnemy=this->leader->findClosestCharacter(enemyTeam->team);
                }
                if(closestEnemy== nullptr){
                    return;// No team members left alive
                }
                character->damage(closestEnemy);
            }
        }
    }

    void Team::print()  {
        for (const auto &character: team) {
            character->print();
        }
    }

    Team::~Team() {
        for (auto &character: team) {
            delete character;
        }
    }

    Character *Team::getLeader() const {
        return leader;
    }

    void Team::setLeader(Character *leader) {
        if (leader != nullptr) {
            if (!leader->getInGroup()) {
                throw std::runtime_error("The leader is not part of this team");
            }
            this->leader = leader;
        }
    }

} // ariel