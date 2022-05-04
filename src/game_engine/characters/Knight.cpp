#include <iostream>

#include "Knight.hpp"

// CONSTRUCTORS
Knight::Knight(const std::string& name)
    : _caracs(Caracteristics(name, 125))
{
}

// DESTRUCTORS
Knight::~Knight()
{
}

// GETTERS

// SETTERS

// METHODS
void Knight::introduce_themself()
{
    std::cout << "Hi there, I'm " << _caracs._name << ", the Knight.\n";
}