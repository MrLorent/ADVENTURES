#pragma once
#define GAME_STATE_MANAGER

#include "start_menu.hpp"
#include "main_menu.hpp"
#include "stats_menu.hpp"
#include "tavern_menu.hpp"
#include "quest_menu.hpp"

// CONSTANTS
enum Menus {
    Start_Menu               = 0,
    Character_Initialisation = 1,
    Main_Menu                = 2,
    Stats_Menu               = 3,
    Tavern_Menu              = 4,
    Quest_Menu               = 5,
    Quit                     = 6,
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
