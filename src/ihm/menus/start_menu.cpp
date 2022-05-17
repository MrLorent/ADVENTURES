#include "menu_commons.hpp"
#include "start_menu.hpp"

void display_start_menu();

void display_start_menu()
{
    display_main_title("START MENU");
    display_menu_options(start_menu);
}

void show_start_menu()
{
    display_start_menu();
}