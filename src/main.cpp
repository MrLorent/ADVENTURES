#include <iostream>

#include "random.hpp"
#include "casts.hpp"
#include "display_functions.hpp"

#include "GameStateManager.hpp"
#include "Character.hpp"
#include "character_initialization.hpp"
#include "monster_initialization.hpp"

int main()
{
    while (true) {
        get_random_monster();
        wait_for_any_key_pressed();
    }
    GameStateManager game_manager;
    Character        player;
    float            quest_duration = 0.f;
    bool             quit           = false;

    while (!quit) {
        switch (game_manager._state) {
        case Menus::Start_Menu: {
            const char command = show_start_menu();
            game_manager.set_state(command);
        } break;

        case Menus::Character_Initialisation: {
            player = create_new_character();
            game_manager.set_state(Menus::Main_Menu);
        } break;

        case Menus::Main_Menu: {
            const char command = show_main_menu();
            game_manager.set_state(command);
        } break;

        case Menus::Tavern_Menu: {
            const char command = show_tavern_menu(quest_duration);
            game_manager.set_state(command);
        } break;

        case Menus::Quest_Menu: {
            show_countdown_menu(quest_duration);
        } break;

        case Menus::Quit: {
            quit = true;
        } break;

        default:
            break;
        }
    }
    clear_console();
    display_text("See you ;)");
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