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
    int         get_health() const { return _caracs._health_points; }

    // SETTERS
    void set_name(const std::string& new_name) { _caracs._name = new_name; }
    void set_health_points(const int new_health_points) { _caracs._health_points = new_health_points; }

    // METHODS
    void introduce_themself() const;
};
