#include "Caracteristics.hpp"

// CONSTRUCTORS
Caracteristics::Caracteristics(const std::string& name, const unsigned int health)
    : _name(name), _experience(0), _health_points(health), _nb_critics_successes(0), _nb_throws(0)
{
}

// DESTRUCTORS
Caracteristics::~Caracteristics()
{
}