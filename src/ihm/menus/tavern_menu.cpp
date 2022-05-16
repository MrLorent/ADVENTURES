#include "random.hpp"
#include "display_functions.hpp"
#include "tavern_menu.hpp"

void show_tavern_menu()
{
    display_main_title("TAVERN");
    display_menu_options(tavern_menu);
}