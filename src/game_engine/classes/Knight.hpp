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
    std::string get_name() const { return _caracs._name; }

    // SETTERS
    void set_name(const std::string& new_name) { _caracs._name = new_name; }

    // METHODS
    void introduce_themself() const;
};
