#pragma once
#define CHARACTER_INITIALISATION_HPP

#include <iostream>

#include "display_functions.hpp"

#include "classes_menu.hpp"

template<class C>
C create_new_character()
{
    display_main_title("CHARACTER CREATION");
    display_text("Enter your pseudoname :");
}