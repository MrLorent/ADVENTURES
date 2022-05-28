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

using Class = std::variant<Archer, Knight, Magician>;

class Character {
private:
    // ATTRIBUT
    Class _class;

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
    std::string get_name_and_title() const;
    int         get_health() const;
    int         get_experience() const;

    // SETTERS
    void set_name(const std::string& new_name);
    void set_health_points(const int new_health_points);

    // METHODS
    void  introduce_themself() const;
    int   attacks() const;
    float get_damages() const;
    bool  dodges() const;
    void  add_experience(const int experience);
};
