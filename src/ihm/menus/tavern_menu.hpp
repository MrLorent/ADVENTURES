#pragma once
#define TAVERN_MENU_HPP

#include <map>

#include "menu_commons.hpp"

enum class TavernMenu : char {
    Quest_1 = '1',
    Quest_2 = '2',
    Quest_3 = '3',
    Quit    = 'q',
};

const std::map<TavernMenu, std::string> tavern_menu_labels = {
    {TavernMenu::Quest_1, "Quest 1"},
    {TavernMenu::Quest_2, "Quest 2"},
    {TavernMenu::Quest_3, "Quest 3"},
    {TavernMenu::Quit, "Quit Tavern"},
};

const std::map<TavernMenu, char> tavern_menu_commands = {
    {TavernMenu::Quest_1, '1'},
    {TavernMenu::Quest_2, '2'},
    {TavernMenu::Quest_3, '3'},
    {TavernMenu::Quit, 'Q'},
};

constexpr std::initializer_list<TavernMenu> tavern_menu_options = {
    TavernMenu::Quest_1,
    TavernMenu::Quest_2,
    TavernMenu::Quest_3,
    TavernMenu::Quit,
};

const Menu<TavernMenu> tavern_menu(
    "Choose your quest :",
    tavern_menu_labels,
    tavern_menu_commands,
    tavern_menu_options,
    'q' /* LAST COMMAND OF THE MENU */);

char show_tavern_menu(float& selected_quest_duration);