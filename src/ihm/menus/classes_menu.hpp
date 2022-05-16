#pragma once
#define CLASSES_MENU_HPP

#include <map>

#include "menu_commons.hpp"

enum class ClassesMenu : char {
    Archer   = '1',
    Knight   = '2',
    Magician = '3',
};

const std::map<ClassesMenu, std::string> classes_menu_labels = {
    {ClassesMenu::Archer, "Archer"},
    {ClassesMenu::Knight, "Knight"},
    {ClassesMenu::Magician, "Magician"},
};

const std::map<ClassesMenu, char> classes_menu_commands = {
    {ClassesMenu::Archer, '1'},
    {ClassesMenu::Knight, '2'},
    {ClassesMenu::Magician, '3'},
};

constexpr std::initializer_list<ClassesMenu> classes_menu_options = {
    ClassesMenu::Archer,
    ClassesMenu::Knight,
    ClassesMenu::Magician,
};

const Menu<ClassesMenu> classes_menu(
    classes_menu_labels,
    classes_menu_commands,
    classes_menu_options,
    '3' /* LAST COMMAND OF THE MENU */);

void show_classes_menu();