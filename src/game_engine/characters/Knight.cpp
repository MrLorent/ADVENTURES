#include <iostream>

#include "Knight.hpp"

// CONSTRUCTORS
Knight::Knight()
    : _caracs(Caracteristics("unknown", 125))
{
}

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
void Knight::introduce_themself() const
{
    std::cout << "Hi there, I'm " << _caracs._name << ", the Knight.\n";
}