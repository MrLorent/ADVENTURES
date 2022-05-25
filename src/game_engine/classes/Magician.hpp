#pragma once
#define MAGICIAN_HPP

#include "Caracteristics.hpp"

class Magician {
private:
    // ATTRIBUTS
    Caracteristics _caracs;

public:
    // CONSTRUCTORS
    Magician();
    Magician(const std::string& name);

    // DESTRUCTORS
    ~Magician();

    // GETTERS
    std::string get_name() const { return _caracs._name; }

    // SETTERS
    void set_name(const std::string& new_name) { _caracs._name = new_name; }

    // METHODS
    void introduce_themself() const;
};
