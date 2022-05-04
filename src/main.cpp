#include <iostream>

#include "random.hpp"
#include "display_functions.hpp"
#include "user_input.hpp"

#include "main_menu.hpp"
#include "Character.hpp"
#include "character_init.hpp"

int main()
{
    Character player;
    bool      quit = false;

    while (!quit) {
        show_main_menu();
        const char command = get_command_from_user();

        switch (command) {
        case static_cast<int>(main_menu::New_game):
            player = Character(Magician("Gandalf"));
            player.introduce_themself();
            wait_for_any_key_pressed();
            break;
        case static_cast<int>(main_menu::Quit):
            quit = true;
            clear_console();
            display_text("See you ;)");
            break;
        default:
            std::cout << "Error [main.cpp] : Wrong command entered.\n";
            break;
        }
    }
}