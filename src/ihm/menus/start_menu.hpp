#pragma once
#define MAIN_MENU_HPP

#include <map>

#include "menu_commons.hpp"

enum class StartMenu : char {
    New_game = '1',
    Quit     = 'q',
};

const std::map<StartMenu, std::string> start_menu_labels = {
    {StartMenu::New_game, "New Game"},
    {StartMenu::Quit, "Quit"},
};

const std::map<StartMenu, char> start_menu_commands = {
    {StartMenu::New_game, '1'},
    {StartMenu::Quit, 'Q'},
};

constexpr std::initializer_list<StartMenu> start_menu_options = {
    StartMenu::New_game,
    StartMenu::Quit,
};

const Menu<StartMenu> start_menu(
    "What do you want to do ?\n",
    start_menu_labels,
    start_menu_commands,
    start_menu_options,
    'q' /* LAST COMMAND OF THE MENU */);

char show_start_menu();