#pragma once
#define MAIN_MENU_HPP

#include <map>

enum class menu_options : char {
    New_game = '1',
    Quit     = 'q',
};

const std::map<menu_options, std::string> main_menu_labels = {
    {menu_options::New_game, "New Game"},
    {menu_options::Quit, "Quit"},
};

const std::map<menu_options, char> main_menu_commands = {
    {menu_options::New_game, '1'},
    {menu_options::Quit, 'Q'},
};

constexpr std::initializer_list<menu_options> main_menu_options = {
    menu_options::New_game,
    menu_options::Quit,
};

void show_main_menu();
char get_command_from_user();