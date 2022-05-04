#pragma once
#define CHARACTER_HPP

#include <variant>

#include "Archer.hpp"
#include "Knight.hpp"
#include "Magician.hpp"

class Character {
private:
    // ATTRIBUT
    std::variant<Archer, Knight, Magician> _type;

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
