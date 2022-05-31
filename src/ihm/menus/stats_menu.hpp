#pragma once
#define STATS_MENU_HPP

#include "Character.hpp"
#include "menu_commons.hpp"

enum class StatsMenu : char {
    Quit = 'q',
};

const std::map<StatsMenu, std::string> stats_menu_labels = {
    {StatsMenu::Quit, "Quit Game"},
};

const std::map<StatsMenu, char> stats_menu_commands = {
    {StatsMenu::Quit, 'Q'},
};

constexpr std::initializer_list<StatsMenu> stats_menu_options = {
    StatsMenu::Quit,
};

const Menu<StatsMenu> stats_menu(
    "Press Q to quit",
    stats_menu_labels,
    stats_menu_commands,
    stats_menu_options,
    'q' /* LAST COMMAND OF THE MENU */);

char show_stats_menu(const Character& player);