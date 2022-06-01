#include <cassert>

#include "user_input.hpp"
#include "difficulty_menu.hpp"

void display_difficulty_menu()
{
    display_main_title("DIFFICULTY");
    display_menu_options(difficulty_menu);
}

void show_difficulty_menu(Difficulty& game_difficulty)
{
    display_difficulty_menu();

    const char command = get_command_from_user<Difficulty>(difficulty_menu, &display_difficulty_menu);

    switch (command) {
    case static_cast<int>(Difficulty::Peaceful): {
        game_difficulty = Difficulty::Peaceful;
    } break;

    case static_cast<int>(Difficulty::Easy): {
        game_difficulty = Difficulty::Easy;
    } break;

    case static_cast<int>(Difficulty::Normal): {
        game_difficulty = Difficulty::Normal;
    } break;

    case static_cast<int>(Difficulty::Hard): {
        game_difficulty = Difficulty::Hard;
    } break;

    case static_cast<int>(Difficulty::Impossible): {
        game_difficulty = Difficulty::Impossible;
    } break;

    case static_cast<int>(Difficulty::Quit): {
    } break;

    default:
        assert(false && "[Error] game difficulty asked is undefine.");
        break;
    }
}