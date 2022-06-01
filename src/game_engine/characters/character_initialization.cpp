#include <cassert>

#include "random.hpp"
#include "character_initialization.hpp"

Character create_new_character()
{
    Character   new_player;
    std::string user_pseudoname;
    display_main_title("NEW CHARACTER - NAME");
    display_text("Enter your pseudoname :\n");

    do {
        user_pseudoname = get_input_from_user<std::string>();
    } while (user_pseudoname.empty());

    show_classes_menu();
    const char command = get_command_from_user<ClassesMenu>(classes_menu, &show_classes_menu);

    switch (command) {
    case static_cast<int>(ClassesMenu::Archer):
        new_player = Character(Archer(user_pseudoname));
        break;
    case static_cast<int>(ClassesMenu::Knight):
        new_player = Character(Knight(user_pseudoname));
        break;
    case static_cast<int>(ClassesMenu::Magician):
        new_player = Character(Magician(user_pseudoname));
        break;
    default:
        assert(false && "[Error] class entered undefined.");
        break;
    }

    return new_player;
}

Character create_random_character()
{
    Character new_character;
    const int random_class = throw_dice(3);

    switch (random_class) {
    case static_cast<int>(Classes::Archer):
        new_character = Character(Archer());
        break;
    case static_cast<int>(Classes::Knight):
        new_character = Character(Knight());
        break;
    case static_cast<int>(Classes::Magician):
        new_character = Character(Magician());
        break;
    default:
        assert(false && "[Error] random_class is out of range of list_of_classes");
        break;
    }

    return new_character;
}