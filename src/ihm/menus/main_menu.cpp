#include "display_functions.hpp"
#include "user_input.hpp"
#include "main_menu.hpp"

bool main_menu_contains_command(const char command);

char get_command_from_user()
{
    char user_choice = get_input_from_user<char>();

    while (!main_menu_contains_command(user_choice)) {
        show_main_menu();

        std::string error_message = "Error : ";
        error_message += user_choice;
        error_message += " isn't an option.";

        std::cout << error_message + "\n";
        user_choice = get_input_from_user<char>();
    };

    return std::tolower(user_choice);
}

bool main_menu_contains_command(const char command)
{
    for (auto command_name : main_menu_list_of_options) {
        if (command == main_menu_commands.at(command_name) || command == char(main_menu_commands.at(command_name) + ('a' - 'A')))
            return true;
    }

    return false;
}

void show_main_menu()
{
    display_main_title("MAIN MENU");
    std::string menu = "What do you want to do ?\n";

    for (auto command : main_menu_list_of_options) {
        menu += " ";
        menu += main_menu_commands.at(command);
        menu += ". " + main_menu_labels.at(command) + "\n";
    }

    display_text(menu);
}