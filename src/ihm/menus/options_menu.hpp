#pragma once
#define OPTIONS_MENU_HPP

#include <map>

#include "menu_commons.hpp"

enum class OptionsMenu : char {
    Difficulty = '1',
    Quit       = 'q',
};

const std::map<OptionsMenu, std::string> options_menu_labels = {
    {OptionsMenu::Difficulty, "Difficulty"},
    {OptionsMenu::Quit, "Quit options"},
};

const std::map<OptionsMenu, char> options_menu_commands = {
    {OptionsMenu::Difficulty, '1'},
    {OptionsMenu::Quit, 'Q'},
};

constexpr std::initializer_list<OptionsMenu> options_menu_options = {
    OptionsMenu::Difficulty,
    OptionsMenu::Quit,
};

const Menu<OptionsMenu> options_menu(
    "Which parameter do you want to change ?\n",
    options_menu_labels,
    options_menu_commands,
    options_menu_options,
    'q' /* LAST COMMAND OF THE MENU */);

char show_options_menu();