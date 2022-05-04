#pragma once
#define ARCHER_HPP

#include "Caracteristics.hpp"

class Archer {
private:
    // ATTRIBUTS
    Caracteristics _caracs;

public:
    // CONSTRUCTORS
    Archer();
    Archer(const std::string& name);

    // DESTRUCTORS
    ~Archer();

    // GETTERS

    // SETTERS

    // METHODS
    void introduce_themself();
};
