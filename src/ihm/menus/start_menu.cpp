#include "menu_commons.hpp"
#include "start_menu.hpp"

void display_start_menu();

void display_start_menu()
{
    display_main_title("START MENU");
    display_menu_options(start_menu);
}

char show_start_menu()
{
    display_start_menu();

    return get_command_from_user<StartMenu>(start_menu, &display_start_menu);
}