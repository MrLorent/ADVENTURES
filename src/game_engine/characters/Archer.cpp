#include <iostream>

#include "Archer.hpp"

// CONSTRUCTORS
Archer::Archer(const std::string& name)
    : _caracs(Caracteristics(name, 100))
{
}

// DESTRUCTORS
Archer::~Archer()
{
}

// GETTERS

// SETTERS

// METHODS
void Archer::introduce_themself()
{
    std::cout << "Hi there, I'm " << _caracs._name << ", the Archer.\n";
}