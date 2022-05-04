#pragma once
#define CHARACTER_INITIALISATION_HPP

#include <iostream>

#include "user_input.hpp"
#include "display_functions.hpp"

#include "classes_menu.hpp"

template<class C>
C create_new_character()
{
    std::string user_pseudoname;
    display_main_title("CHARACTER CREATION");
    display_text("Enter your pseudoname :");

    do {
        user_pseudoname = get_input_from_user<std::string>();
    } while (user_pseudoname.empty());
}