#include "team2.hpp"
#include <stdexcept>
using namespace std;

namespace ariel{

    Team2::Team2(Character *leader) : Team(leader) {
    }

    void Team2::add(Character *character) {
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
    }

} // ariel