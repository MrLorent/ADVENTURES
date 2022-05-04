#pragma once
#define MAGICIAN_HPP

#include "Caracteristics.hpp"

class Magician {
private:
    // ATTRIBUTS
    Caracteristics _caracs;

public:
    // CONSTRUCTORS
    Magician(const std::string& name);

    // DESTRUCTORS
    ~Magician();

    // GETTERS

    // SETTERS

    // METHODS
    void introduce_themself();
};
