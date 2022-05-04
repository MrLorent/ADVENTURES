#include <iostream>
#include <variant>

#include "random.hpp"
#include "display_functions.hpp"
#include "user_input.hpp"

#include "main_menu.hpp"
#include "character_classes.hpp"

int main()
{
    // Knight   the_knight("Gontrand");
    // Archer   the_archer("Theophile");
    // Magician the_magician("Ivancéliandre");

    // the_knight.introduce_themself();
    // the_archer.introduce_themself();
    // the_magician.introduce_themself();
    std::variant<Archer, Knight, Magician> player;
    bool                                   quit = false;

    auto call_introduce_themself = [](auto& character) { character.introduce_themself(); };

    while (!quit) {
        show_main_menu();
        const char command = get_command_from_user();

        switch (command) {
        case static_cast<int>(main_menu_options::New_game):
            player = Magician("Gandalf");
            std::visit(call_introduce_themself, player);
            wait_for_any_key_pressed();
            break;
        case static_cast<int>(main_menu_options::Quit):
            quit = true;
            clear_console();
            display_text("See you ;)");
            break;
        default:
            std::cout << "Error [main.cpp] : Wrong command entered.\n";
            break;
        }
    }
}