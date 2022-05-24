#pragma once
#define FIGHT_MENU

#include <string>
#include <vector>

struct Monster {
    const std::string _name;
    const int         _experience;

    Monster()
        : _name("unknown"), _experience(0)
    {
    }

    Monster(const std::string name, const int experience)
        : _name(name), _experience(experience)
    {
    }
};

std::vector<Monster> load_monsters();