#pragma once
#define CHARACTER_HPP

#include <variant>

#include "Archer.hpp"
#include "Knight.hpp"
#include "Magician.hpp"

using CharacterClass = std::variant<Archer, Knight, Magician>;

class Character {
private:
    // ATTRIBUT
    CharacterClass _type;

public:
    // CONSTRUCTORS
    Character();
    Character(Archer archer);
    Character(Knight knight);
    Character(Magician magician);

    // DESTRUCTORS
    ~Character();

    // GETTERS

    // SETTERS

    // METHODS
    void introduce_themself() const;
};
