#pragma once
#define KNIGHT_HPP

#include "Caracteristics.hpp"

class Knight {
private:
    // ATTRIBUTS
    Caracteristics _caracs;

public:
    // CONSTRUCTORS
    Knight();
    Knight(const std::string& name);

    // DESTRUCTORS
    ~Knight();

    // GETTERS

    // SETTERS

    // METHODS
    void introduce_themself();
};
