#include <iostream>

#include "random.hpp"
#include "display_functions.hpp"
#include "user_input.hpp"

#include "GameStateManager.hpp"
#include "start_menu.hpp"
#include "Character.hpp"
#include "character_init.hpp"
#include "main_menu.hpp"
#include "tavern_menu.hpp"

int main()
{
    GameStateManager game_manager;
    Character        player;
    bool             quit = false;

    while (!quit) {
        switch (game_manager._state) {
        case Menus::Start_Menu:
            show_start_menu();
            wait_for_any_key_pressed();
            //const char command = get_command_from_user<StartMenu>(start_menu, &show_start_menu);
            break;
        default:
            break;
        }
        // show_start_menu();
        // const char command = get_command_from_user<StartMenu>(start_menu, &show_start_menu);

        // switch (command) {
        // case static_cast<int>(StartMenu::New_game): {
        //     player         = create_new_character();
        //     bool game_quit = false;

        //     while (!game_quit) {
        //         show_main_menu();
        //         const char action = get_command_from_user<MainMenu>(main_menu, &show_main_menu);

        //         switch (action) {
        //         case static_cast<int>(MainMenu::Tavern):
        //             show_tavern_menu();
        //             wait_for_any_key_pressed();
        //             break;
        //         case static_cast<int>(MainMenu::Quit):
        //             game_quit = true;
        //             break;
        //         default:
        //             std::cout << "Error [main.cpp] : Wrong command entered.\n";
        //             break;
        //         }
        //     }
        // } break;
        // case static_cast<int>(StartMenu::Quit):
        //     quit = true;
        //     clear_console();
        //     display_text("See you ;)");
        //     break;
        // default:
        //     std::cout << "Error [main.cpp] : Wrong command entered.\n";
        //     break;
        // }
    }
}