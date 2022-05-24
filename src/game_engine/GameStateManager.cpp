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
        case static_cast<int>(StartMenu::Quit):
            _state = Menus::Quit;
            break;
        default:
            break;
        }
    } break;

    case Menus::Character_Initialisation:
        /* code */
        break;

    case Menus::Main_Menu: {
        switch (command) {
        case static_cast<int>(MainMenu::Tavern):
            _state = Menus::Tavern_Menu;
            break;
        case static_cast<int>(MainMenu::Quit):
            _state = Menus::Start_Menu;
            break;
        default:
            break;
        }
    } break;

    case Menus::Tavern_Menu:
        switch (command) {
        case static_cast<int>(TavernMenu::Quest_1):
            _state = Menus::Quest_Menu;
            break;
        case static_cast<int>(TavernMenu::Quest_2):
            _state = Menus::Quest_Menu;
            break;
        case static_cast<int>(TavernMenu::Quest_3):
            _state = Menus::Quest_Menu;
            break;
        case static_cast<int>(TavernMenu::Quit):
            _state = Menus::Main_Menu;
            break;
        default:
            break;
        }
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