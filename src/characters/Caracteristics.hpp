#pragma once
#define CARACTERISTICS_HPP

#include <string>

struct Caracteristics {
    // ATTRIBUTS
    std::string        _name;
    short unsigned int _level;
    unsigned int       _health;

    // CONSTRUCTORS
    Caracteristics(const std::string& name, const unsigned int health);

    // DESTRUCTORS
    ~Caracteristics();
};
