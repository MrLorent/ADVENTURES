#include "GameStateManager.hpp"

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
void GameStateManager::set_state(const char command)
{
    switch (_state) {
    case Menus::Start_Menu: {
        switch (command) {
        case static_cast<int>(StartMenu::New_game):
            _state = Menus::Character_Initialisation;
            break;
        default:
            break;
        }
    } break;
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

void GameStateManager::set_state(const int new_state)
{
    _state = new_state;
}

// METHODS