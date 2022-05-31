#include "options_menu.hpp"

void display_options_menu();

void display_options_menu()
{
    display_main_title("OPTIONS");
    display_menu_options(options_menu);
}

char show_options_menu()
{
    display_options_menu();

    return get_command_from_user<OptionsMenu>(options_menu, &display_options_menu);
}