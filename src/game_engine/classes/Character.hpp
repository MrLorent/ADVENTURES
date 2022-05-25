#pragma once
#define CHARACTER_HPP

#include <variant>

#include "Archer.hpp"
#include "Knight.hpp"
#include "Magician.hpp"

enum class Classes : int {
    Archer   = 1,
    Knight   = 2,
    Magician = 3,
};

constexpr std::initializer_list<Classes> list_of_classes = {
    Classes::Archer,
    Classes::Knight,
    Classes::Magician,
};

using CharacterClass = std::variant<Archer, Knight, Magician>;

class Character {
private:
    // ATTRIBUT
    CharacterClass _class;

public:
    // CONSTRUCTORS
    Character();
    Character(Archer archer);
    Character(Knight knight);
    Character(Magician magician);

    // DESTRUCTORS
    ~Character();

    // GETTERS
    std::string get_name() const;

    // SETTERS
    void set_name(const std::string& new_name);

    // METHODS
    void introduce_themself() const;
};
