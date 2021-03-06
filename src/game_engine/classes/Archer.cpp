#include <iostream>

#include "Archer.hpp"
#include "attack_states.hpp"
#include "random.hpp"

// CONSTRUCTORS
Archer::Archer()
    : _caracs(Caracteristics("unknown", 25))
{
}

Archer::Archer(const std::string& name)
    : _caracs(Caracteristics(name, 25))
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
    return 5 + (_caracs._experience * 75 / 700) * 0.5;
}

bool Archer::dodges() const
{
    const float p = 0.15 + 0.20 * (_caracs._experience * 676 / 62000);
    return bernoulli(1 - p);
}

void Archer::add_experience(const int experience)
{
    _caracs._experience += experience;
}