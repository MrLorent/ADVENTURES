#include "GameStateManager.hpp"
#include <iostream>

// CONSTRUCTORS
GameStateManager::GameStateManager()
    : _state(Menus::Start_Menu)
{
}

// DESTRUCTORS
GameStateManager::~GameStateManager()
{
}

// GETTERS

// SETTERS
void GameStateManager::set_game_state(const short unsigned int new_state, const char command)
{
    switch (_state) {
    case Menus::Start_Menu:
        std::cout << new_state << std::endl;
        std::cout << command << std::endl;
        break;
    case Menus::Character_Initialisation:
        /* code */
        break;
    case Menus::Main_Menu:
        /* code */
        break;
    case Menus::Tavern_Menu:
        /* code */
        break;
    case Menus::Quit:
        /* code */
        break;
    default:
        break;
    }
}

// METHODS