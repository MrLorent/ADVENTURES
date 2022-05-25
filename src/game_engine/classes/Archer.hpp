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
    std::string get_name() const { return _caracs._name; }

    // SETTERS
    void set_name(const std::string& new_name) { _caracs._name = new_name; }

    // METHODS
    void introduce_themself() const;
};
