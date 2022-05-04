#include <iostream>

#include "Magician.hpp"

// CONSTRUCTORS
Magician::Magician()
    : _caracs(Caracteristics("unknown", 75))
{
}

Magician::Magician(const std::string& name)
    : _caracs(Caracteristics(name, 75))
{
}

// DESTRUCTORS
Magician::~Magician()
{
}

// GETTERS

// SETTERS

// METHODS
void Magician::introduce_themself() const
{
    std::cout << "Hi there, I'm " << _caracs._name << ", the Magician.\n";
}