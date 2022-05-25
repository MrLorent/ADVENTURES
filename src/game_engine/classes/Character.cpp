#include "Character.hpp"

// CONSTRUCTORS
Character::Character()
{
}

Character::Character(Archer archer)
    : _class(archer)
{
}

Character::Character(Knight knight)
    : _class(knight)
{
}

Character::Character(Magician magician)
    : _class(magician)
{
}

// DESTRUCTORS
Character::~Character()
{
}

// GETTERS
std::string Character::get_name() const
{
    auto call_get_name = [](auto& character) { return character.get_name(); };
    return std::visit(call_get_name, _class);
}

// SETTERS
void Character::set_name(const std::string& new_name)
{
    std::variant<const std::string> param_name(new_name);

    auto call_set_name = [](auto& character, const std::string new_name) { character.set_name(new_name); };
    std::visit(call_set_name, _class, param_name);
}

// METHODS
void Character::introduce_themself() const
{
    auto call_introduce_themself = [](auto& character) { character.introduce_themself(); };
    std::visit(call_introduce_themself, _class);
}