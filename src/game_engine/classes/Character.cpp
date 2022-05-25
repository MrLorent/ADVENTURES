#include "Character.hpp"

// CONSTRUCTORS
Character::Character()
{
}

Character::Character(Archer archer)
    : _type(archer)
{
}

Character::Character(Knight knight)
    : _type(knight)
{
}

Character::Character(Magician magician)
    : _type(magician)
{
}

// DESTRUCTORS
Character::~Character()
{
}

// GETTERS

// SETTERS

// METHODS
void Character::introduce_themself() const
{
    auto call_introduce_themself = [](auto& character) { character.introduce_themself(); };
    std::visit(call_introduce_themself, _type);
}