#pragma once
#define GAME_STATE_MANAGER

#include "start_menu.hpp"
#include "main_menu.hpp"
#include "tavern_menu.hpp"

// CONSTANTS
enum Menus {
    Start_Menu               = 0,
    Character_Initialisation = 1,
    Main_Menu                = 2,
    Tavern_Menu              = 3,
    Quest_Countdown          = 4,
    Quit                     = 5,
};

struct GameStateManager {
    // ATTRIBUTS
    short unsigned int _state;

    // CONSTRUCTORS
    GameStateManager();

    // DESTRUCTORS
    ~GameStateManager();

    // GETTERS

    // SETTERS
    void set_state(const char command);
    void set_state(const int new_state);

    // METHODS
};
