#pragma once
#define MENU_COMMONS_HPP

#include <map>

#include "display_functions.hpp"
#include "user_input.hpp"

template<class T>
struct Menu {
    const std::string              _instruction;
    const std::map<T, std::string> _labels;
    const std::map<T, char>        _commands;
    const std::initializer_list<T> _options;

    const char _last_command;

    Menu(const std::string               instruction,
         const std::map<T, std::string>& labels,
         const std::map<T, char>&        commands,
         const std::initializer_list<T>& options,
         const char                      last_command)
        : _instruction(instruction), _labels(labels), _commands(commands), _options(options), _last_command(std::tolower(last_command))
    {
    }
};

template<typename T>
void display_menu_options(const Menu<T>& menu)
{
    std::string text_menu = menu._instruction;

    for (auto command : menu._options) {
        text_menu += " ";
        text_menu += menu._commands.at(command);
        text_menu += ". " + menu._labels.at(command) + "\n";
    }

    display_text(text_menu);
}

template<typename T>
char get_command_from_user(const Menu<T>& menu, void (*show_current_menu)())
{
    char user_choice = get_input_from_user<char>();

    while (!menu_contains_command(menu, user_choice)) {
        show_current_menu();

        std::string error_message = "Error : '";
        error_message += user_choice;
        error_message += "' isn't an option.";

        std::cout << error_message + "\n";
        user_choice = get_input_from_user<char>();
    };

    return std::tolower(user_choice);
}

template<typename T>
bool menu_contains_command(const Menu<T>& menu, const char command)
{
    for (auto command_name : menu._options) {
        if (std::tolower(command) == std::tolower(menu._commands.at(command_name)))
            return true;
    }

    return false;
}