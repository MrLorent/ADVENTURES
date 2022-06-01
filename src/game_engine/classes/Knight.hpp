#pragma once
#define KNIGHT_HPP

#include "iostream"
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
    int         get_health() const { return _caracs._health_points + (676 * _caracs._experience / 155000) * 1.15; }
    int         get_experience() const { return _caracs._experience; }
    int         get_nb_critic_successes() const { return _caracs._nb_critics_successes; }
    int         get_nb_throws() const { return _caracs._nb_throws; }

    // SETTERS
    void set_name(const std::string& new_name) { _caracs._name = new_name; }
    void set_health_points(const int new_health_points) { _caracs._health_points = new_health_points; }
    void add_nb_critic_successes(const unsigned int nb_critics) { _caracs._nb_critics_successes += nb_critics; }
    void add_nb_throws(const unsigned int nb_throws) { _caracs._nb_throws += nb_throws; }
    void increment_nb_critic_successes() { _caracs._nb_critics_successes += 1; }
    void increment_nb_throws() { _caracs._nb_throws += 1; }

    // METHODS
    void  introduce_themself() const;
    int   attacks();
    float get_damages() const;
    bool  dodges() const;
    void  add_experience(const int experience);
};
