#pragma once
#define MAIN_MENU_HPP

#include <map>

#include "menu_commons.hpp"

enum class MainMenu : char {
    New_game = '1',
    Quit     = 'q',
};

const std::map<MainMenu, std::string> main_menu_labels = {
    {MainMenu::New_game, "New Game"},
    {MainMenu::Quit, "Quit"},
};

const std::map<MainMenu, char> main_menu_commands = {
    {MainMenu::New_game, '1'},
    {MainMenu::Quit, 'Q'},
};

constexpr std::initializer_list<MainMenu> main_menu_options = {
    MainMenu::New_game,
    MainMenu::Quit,
};

const Menu<MainMenu> main_menu(
    "What do you want to do ?\n",
    main_menu_labels,
    main_menu_commands,
    main_menu_options,
    'q' /* LAST COMMAND OF THE MENU */);

void show_main_menu();