#pragma once
#define DIFFICULTY_MENU_HPP

#include <map>

#include "menu_commons.hpp"
#include "difficulties.hpp"

const std::map<Difficulty, std::string> difficulty_menu_labels = {
    {Difficulty::Peaceful, "Peaceful"},
    {Difficulty::Easy, "Easy"},
    {Difficulty::Normal, "Normal"},
    {Difficulty::Hard, "Hard"},
    {Difficulty::Impossible, "Impossible"},
    {Difficulty::Quit, "Quit difficulty options"},
};

const std::map<Difficulty, char> difficulty_menu_commands = {
    {Difficulty::Peaceful, '1'},
    {Difficulty::Easy, '2'},
    {Difficulty::Normal, '3'},
    {Difficulty::Hard, '4'},
    {Difficulty::Impossible, '5'},
    {Difficulty::Quit, 'Q'},
};

constexpr std::initializer_list<Difficulty> difficulty_menu_options = {
    Difficulty::Peaceful,
    Difficulty::Easy,
    Difficulty::Normal,
    Difficulty::Hard,
    Difficulty::Impossible,
    Difficulty::Quit,
};

const Menu<Difficulty> difficulty_menu(
    "Choose your difficulty :\n",
    difficulty_menu_labels,
    difficulty_menu_commands,
    difficulty_menu_options,
    'q' /* LAST COMMAND OF THE MENU */);

void show_difficulty_menu(Difficulty& game_difficulty);