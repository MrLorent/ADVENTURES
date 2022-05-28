#pragma once
#define CARACTERISTICS_HPP

#include <string>

#include "attack_states.hpp"

struct Caracteristics {
    // ATTRIBUTS
    std::string  _name;
    unsigned int _experience;
    unsigned int _health_points;

    // CONSTRUCTORS
    Caracteristics(const std::string& name, const unsigned int health);

    // DESTRUCTORS
    ~Caracteristics();
};
