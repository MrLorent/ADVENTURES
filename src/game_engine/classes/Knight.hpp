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
    int         get_health() const { return _caracs._health_points; }

    // SETTERS
    void set_name(const std::string& new_name) { _caracs._name = new_name; }
    void set_health_points(const int new_health_points) { _caracs._health_points = new_health_points; }

    // METHODS
    void introduce_themself() const;
};
