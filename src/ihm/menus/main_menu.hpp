#pragma once
#define ACTIONS_MENU

#include <map>

#include "menu_commons.hpp"

enum class MainMenu : char {
    Tavern = '1',
    Quit   = 'q',
};

const std::map<MainMenu, std::string> main_menu_labels = {
    {MainMenu::Tavern, "Go to the Tavern"},
    {MainMenu::Quit, "Quit Game"},
};

const std::map<MainMenu, char> main_menu_commands = {
    {MainMenu::Tavern, '1'},
    {MainMenu::Quit, 'q'},
};

constexpr std::initializer_list<MainMenu> main_menu_options = {
    MainMenu::Tavern,
    MainMenu::Quit,
};

const Menu<MainMenu> main_menu(
    "What do you want to do ?\n",
    main_menu_labels,
    main_menu_commands,
    main_menu_options,
    'q' /* LAST COMMAND OF THE MENU */);

void show_main_menu();