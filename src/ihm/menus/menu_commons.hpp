#pragma once
#define MENU_COMMONS_HPP

#include <map>

template<typename T>
struct Menu {
    const std::map<T, std::string> _labels;
    const std::map<T, char>        _commands;
    const std::initializer_list<T> _options;

    Menu(const std::map<T, std::string>& labels,
         const std::map<T, char>&        commands,
         const std::initializer_list<T>& options)
        : _labels(labels), _commands(commands), _options(options)
    {
    }
};

template<typename T>
bool menu_contains_command(const std::initializer_list<T>& list_of_options, const std::map<T, char>& list_of_commands, const char command)
{
    for (auto command_name : list_of_options) {
        if (std::tolower(command) == std::tolower(list_of_commands.at(command_name)))
            return true;
    }

    return false;
}