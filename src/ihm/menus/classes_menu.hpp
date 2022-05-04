#pragma once
#define CLASSES_MENU_HPP

#include <map>

enum class classes_menu_options : char {
    Archer   = '1',
    Knight   = '2',
    Magician = '3',
};

const std::map<classes_menu_options, std::string> classes_menu_labels = {
    {classes_menu_options::Archer, "Archer"},
    {classes_menu_options::Knight, "Knight"},
    {classes_menu_options::Magician, "Magician"},
};

const std::map<classes_menu_options, char> classes_menu_commands = {
    {classes_menu_options::Archer, '1'},
    {classes_menu_options::Knight, '2'},
    {classes_menu_options::Magician, '3'},
};

constexpr std::initializer_list<classes_menu_options> classes_menu_list_of_options = {
    classes_menu_options::Archer,
    classes_menu_options::Knight,
    classes_menu_options::Magician,
};

void show_classes_menu();