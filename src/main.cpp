#include <iostream>
#include <cassert>

#include "random.hpp"
#include "casts.hpp"
#include "display_functions.hpp"

#include "GameStateManager.hpp"
#include "Character.hpp"
#include "character_initialization.hpp"
#include "fight.hpp"

int main()
{
    GameStateManager game_manager;
    Difficulty       game_difficulty = Difficulty::Normal;
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

        case Menus::Stats_Menu: {
            const char command = show_stats_menu(player);
            game_manager.set_state(command);
        } break;

        case Menus::Options_Menu: {
            const char command = show_options_menu();
            game_manager.set_state(command);
        } break;

        case Menus::Difficulty_Menu: {
            show_difficulty_menu(game_difficulty);
            game_manager.set_state(Menus::Options_Menu);
        } break;

        case Menus::Tavern_Menu: {
            const char command = show_tavern_menu(quest_duration);
            game_manager.set_state(command);
        } break;

        case Menus::Quest_Menu: {
            show_countdown_to_quest(quest_duration);
            fight_against_monster(player, game_difficulty);
            show_countdown_to_tavern(0.05);
            game_manager.set_state(Menus::Main_Menu);
        } break;

        case Menus::Quit: {
            quit = true;
        } break;

        default:
            assert(false && "[Error] game_manager._state asked is undefine.");
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