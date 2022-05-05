#include "character_init.hpp"

Character create_new_character()
{
    Character   new_player;
    std::string user_pseudoname;
    display_main_title("NEW CHARACTER - NAME");
    display_text("Enter your pseudoname :");

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
        std::cout << "Error [character_init.cpp] : Wrong character class entered.\n";
        break;
    }

    return new_player;
}