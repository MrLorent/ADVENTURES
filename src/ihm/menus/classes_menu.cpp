#include "display_functions.hpp"
#include "classes_menu.hpp"

void show_classes_menu()
{
    display_main_title("NEW CHARACTER - CLASS");
    display_menu_options(classes_menu);
}