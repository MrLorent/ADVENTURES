#include <iostream>

#include "Archer.hpp"
#include "attack_states.hpp"
#include "random.hpp"

// CONSTRUCTORS
Archer::Archer()
    : _caracs(Caracteristics("unknown", 100))
{
}

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
void Archer::introduce_themself() const
{
    std::cout << "Hi there, I'm " << _caracs._name << ", the Archer.\n";
}

int Archer::attacks()
{
    int       attack_state = static_cast<int>(Attack_states::Success);
    const int result       = throw_dice(20);

    increment_nb_throws();

    if (result == 1) {
        attack_state = static_cast<int>(Attack_states::Critic_failure);
    }
    else if (result == 20) {
        increment_nb_critic_successes();
        attack_state = static_cast<int>(Attack_states::Critic_success);
    }

    return attack_state;
}

float Archer::get_damages() const
{
    return 5;
}

bool Archer::dodges() const
{
    return bernoulli(0.6f);
}

void Archer::add_experience(const int experience)
{
    _caracs._experience += experience;
}