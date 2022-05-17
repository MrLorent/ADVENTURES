#include "random.hpp"
#include "display_functions.hpp"
#include "tavern_menu.hpp"

void display_tavern_menu();

void display_tavern_menu()
{
    display_main_title("TAVERN");
    display_text(tavern_menu._instruction);

    for (auto command : tavern_menu._options) {
        std::string option_text = " ";
        option_text += tavern_menu._commands.at(command);
        option_text += ". " + tavern_menu._labels.at(command);

        display_text(option_text);
    }
}

void show_tavern_menu()
{
    display_tavern_menu();
}