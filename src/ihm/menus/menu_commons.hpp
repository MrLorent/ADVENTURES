#pragma once
#define MENU_COMMONS_HPP

#include <map>

template<class T>
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
bool menu_contains_command(const Menu<T> menu, const char command)
{
    for (auto command_name : menu._options) {
        if (std::tolower(command) == std::tolower(menu._commands.at(command_name)))
            return true;
    }

    return false;
}