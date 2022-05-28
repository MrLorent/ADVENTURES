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
    std::string get_name_and_title() const { return _caracs._name + " the knight"; }
    int         get_health() const { return _caracs._health_points; }
    int         get_experience() const { return _caracs._experience; }

    // SETTERS
    void set_name(const std::string& new_name) { _caracs._name = new_name; }
    void set_health_points(const int new_health_points) { _caracs._health_points = new_health_points; }

    // METHODS
    void  introduce_themself() const;
    int   attacks() const;
    float get_damages() const;
    bool  dodges() const;
    void  add_experience(const int experience);
};
