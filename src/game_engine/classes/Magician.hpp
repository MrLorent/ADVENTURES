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
    std::string get_name_and_title() const { return _caracs._name + " the magician"; }
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
