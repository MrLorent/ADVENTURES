#include "actions_menu.hpp"

void show_actions_menu()
{
    display_main_title("NEW CHARACTER - CLASS");
    display_menu_options(classes_menu, "What do you want to do ?\n");
}