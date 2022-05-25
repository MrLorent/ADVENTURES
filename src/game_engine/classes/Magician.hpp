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
    int         get_health() const { return _caracs._health_points; }

    // SETTERS
    void set_name(const std::string& new_name) { _caracs._name = new_name; }
    void set_health_points(const int new_health_points) { _caracs._health_points = new_health_points; }

    // METHODS
    void introduce_themself() const;
};
