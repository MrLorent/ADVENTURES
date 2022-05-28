#include <iostream>

#include "random.hpp"
#include "attack_states.hpp"
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

int Magician::attacks() const
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

float Magician::get_damages() const
{
    return 20 + _caracs._experience * 0.065;
}

bool Magician::dodges() const
{
    return bernoulli(0.95f);
}

void Magician::add_experience(const int experience)
{
    _caracs._experience += experience;
}