#include <iostream>

#include "user_input.hpp"
#include "main_menu.hpp"

bool menu_command_contains(const char command);
void display_menu_title();

char get_command_from_user()
{
    char user_choice = get_input_from_user<char>();

    while (!menu_command_contains(user_choice)) {
        show_main_menu();

        std::string error_message = "Error : ";
        error_message += user_choice;
        error_message += " isn't an option.";

        std::cout << error_message + "\n";
        user_choice = get_input_from_user<char>();
    };

    return std::tolower(user_choice);
}

bool menu_command_contains(const char command)
{
    for (auto command_name : main_menu_options) {
        if (command == main_menu_commands.at(command_name) || command == char(main_menu_commands.at(command_name) + ('a' - 'A')))
            return true;
    }

    return false;
}

void show_main_menu()
{
    display_menu_title();
    std::string menu = "What do you want to do ?\n";

    for (auto command : main_menu_options) {
        menu += " ";
        menu += main_menu_commands.at(command);
        menu += ". " + main_menu_labels.at(command) + "\n";
    }

    std::cout << menu + "\n";
}

void display_menu_title()
{
    system("clear");
    std::cout << "|=======| MAIN MENU |=======|\n\n";
}