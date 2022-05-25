#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "casts.hpp"
#include "display_functions.hpp"
#include "quest_menu.hpp"

void display_countdown_menu(const float time, const short unsigned int nb_dots);

void display_countdown_menu(const float time, const short unsigned int nb_dots)
{
    display_main_title("ON THE ROAD");
    display_line("\nYou're on your way to the quest location");
    for (unsigned int i = 0; i < nb_dots; i++) {
        display_line(".");
    }
    display_line("\nTime remaining : ");
    display_decimal_with_precision(time, 2);
    display_text(" minutes\n");
    display_text("\nJust wait and enjoy the road");
}

void show_countdown_menu(const float duration)
{
    float time_remaning     = duration;
    time_remaning           = 0.05;
    short unsigned int dots = 0;

    while (time_remaning >= 0) {
        display_countdown_menu(time_remaning, dots);
        dots == 3 ? dots = 0 : dots++;

        time_remaning -= 0.01;
        if (time_remaning - int(time_remaning) <= 0.01 && time_remaning - int(time_remaning) > 0.f) {
            time_remaning = int(time_remaning) + 0.01;
        }
        else if (time_remaning - int(time_remaning) >= 0.98) {
            time_remaning = int(time_remaning) + 0.59;
        }
        sleep(1);
    }
}