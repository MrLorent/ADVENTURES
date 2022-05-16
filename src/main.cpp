#include <iostream>

#include "random.hpp"
#include "display_functions.hpp"
#include "user_input.hpp"

#include "start_menu.hpp"
#include "Character.hpp"
#include "character_init.hpp"
#include "actions_menu.hpp"
#include "tavern_menu.hpp"

int main()
{
    Character player;
    bool      quit = false;

    while (!quit) {
        show_start_menu();
        const char command = get_command_from_user<StartMenu>(start_menu, &show_start_menu);

        switch (command) {
        case static_cast<int>(StartMenu::New_game): {
            player         = create_new_character();
            bool game_quit = false;

            while (!game_quit) {
                show_actions_menu();
                const char action = get_command_from_user<ActionsMenu>(actions_menu, &show_actions_menu);

                switch (action) {
                case static_cast<int>(ActionsMenu::Tavern):
                    show_tavern_menu();
                    wait_for_any_key_pressed();
                    break;
                case static_cast<int>(ActionsMenu::Quit):
                    game_quit = true;
                    break;
                default:
                    std::cout << "Error [main.cpp] : Wrong command entered.\n";
                    break;
                }
            }
        } break;
        case static_cast<int>(StartMenu::Quit):
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