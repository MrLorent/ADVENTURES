#pragma once
#define GAME_STATE_MANAGER

// CONSTANTS
enum Menus {
    Start_Menu               = 0,
    Character_Initialisation = 1,
    Main_Menu                = 2,
    Tavern_Menu              = 3,
    Quit                     = 4,
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
    void set_game_state(const short unsigned int new_state, const char command);

    // METHODS
};
