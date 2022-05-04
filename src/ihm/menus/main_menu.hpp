#pragma once
#define MAIN_MENU_HPP

#include <map>

#include "menu_commons.hpp"

enum class main_menu_options : char {
    New_game = '1',
    Quit     = 'q',
};

const std::map<main_menu_options, std::string> main_menu_labels = {
    {main_menu_options::New_game, "New Game"},
    {main_menu_options::Quit, "Quit"},
};

const std::map<main_menu_options, char> main_menu_commands = {
    {main_menu_options::New_game, '1'},
    {main_menu_options::Quit, 'Q'},
};

constexpr std::initializer_list<main_menu_options> main_menu_list_of_options = {
    main_menu_options::New_game,
    main_menu_options::Quit,
};

void show_main_menu();
char get_command_from_user();