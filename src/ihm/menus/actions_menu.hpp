#pragma once
#define ACTIONS_MENU

#include <map>

#include "menu_commons.hpp"

enum class ActionsMenu : char {
    Tavern = '1',
    Quit   = 'q',
};

const std::map<ActionsMenu, std::string> actions_menu_labels = {
    {ActionsMenu::Tavern, "Go to the Tavern"},
    {ActionsMenu::Quit, "Quit"},
};

const std::map<ActionsMenu, char> actions_menu_commands = {
    {ActionsMenu::Tavern, '1'},
    {ActionsMenu::Quit, 'q'},
};

constexpr std::initializer_list<ActionsMenu> actions_menu_options = {
    ActionsMenu::Tavern,
    ActionsMenu::Quit,
};

const Menu<ActionsMenu> classes_menu(
    actions_menu_labels,
    actions_menu_commands,
    actions_menu_options,
    'q' /* LAST COMMAND OF THE MENU */);

void show_actions_menu();