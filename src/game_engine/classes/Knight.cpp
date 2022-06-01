#include <iostream>

#include "random.hpp"
#include "attack_states.hpp"
#include "Knight.hpp"

// CONSTRUCTORS
Knight::Knight()
    : _caracs(Caracteristics("unknown", 32))
{
}

Knight::Knight(const std::string& name)
    : _caracs(Caracteristics(name, 32))
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

int Knight::attacks()
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

float Knight::get_damages() const
{
    return 7 + (_caracs._experience * 75 / 700) * 0.65;
}

bool Knight::dodges() const
{
    const float p = 0.10 + 0.15 * (_caracs._experience * 676 / 62000);
    return bernoulli(1 - p);
}

void Knight::add_experience(const int experience)
{
    _caracs._experience += experience;
}