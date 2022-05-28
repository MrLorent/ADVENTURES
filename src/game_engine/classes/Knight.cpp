#include <iostream>

#include "random.hpp"
#include "attack_states.hpp"
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

int Knight::attacks() const
{
    int       attack_state = static_cast<int>(Attack_states::Success);
    const int result       = throw_dice(20);

    if (result == 1) {
        attack_state = static_cast<int>(Attack_states::Critic_failure);
    }
    else if (result == 20) {
        attack_state = static_cast<int>(Attack_states::Critic_success);
    }

    return attack_state;
}

float Knight::get_damages() const
{
    return 10 + _caracs._experience * 0.05;
}

bool Knight::dodges() const
{
    return bernoulli(0.75f);
}

void Knight::add_experience(const int experience)
{
    _caracs._experience += experience;
}