#include "menu_commons.hpp"
#include "main_menu.hpp"

void display_main_menu();

void display_main_menu()
{
    display_main_title("VILLAGE");
    display_menu_options(main_menu);
}

char show_main_menu()
{
    display_main_menu();

    return get_command_from_user<MainMenu>(main_menu, &display_main_menu);
}