#pragma once
#define MAIN_MENU_HPP

#include <map>

#include "menu_commons.hpp"

enum class main_menu : char {
    New_game = '1',
    Quit     = 'q',
};

const std::map<main_menu, std::string> main_menu_labels = {
    {main_menu::New_game, "New Game"},
    {main_menu::Quit, "Quit"},
};

const std::map<main_menu, char> main_menu_commands = {
    {main_menu::New_game, '1'},
    {main_menu::Quit, 'Q'},
};

constexpr std::initializer_list<main_menu> main_menu_options = {
    main_menu::New_game,
    main_menu::Quit,
};

void show_main_menu();
char get_command_from_user();