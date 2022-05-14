#include <iostream>

#include "random.hpp"
#include "display_functions.hpp"
#include "user_input.hpp"

#include "main_menu.hpp"
#include "Character.hpp"
#include "character_init.hpp"

int main()
{
    while (true) {
        std::cout << box_muller(10, 1.75);
        wait_for_any_key_pressed();
    }

    // Character player;
    // bool      quit = false;

    // while (!quit) {
    //     show_main_menu();
    //     const char command = get_command_from_user<MainMenu>(main_menu, &show_main_menu);

    //     switch (command) {
    //     case static_cast<int>(MainMenu::New_game):
    //         player = create_new_character();
    //         clear_console();
    //         player.introduce_themself();
    //         wait_for_any_key_pressed();
    //         break;
    //     case static_cast<int>(MainMenu::Quit):
    //         quit = true;
    //         clear_console();
    //         display_text("See you ;)");
    //         break;
    //     default:
    //         std::cout << "Error [main.cpp] : Wrong command entered.\n";
    //         break;
    //     }
    // }
}