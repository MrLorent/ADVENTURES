#include "string_tools.hpp"
#include "display_functions.hpp"
#include "user_input.hpp"

#include "stats_menu.hpp"

namespace {
Character PLAYER;
} // namespace

void display_stats_menu();

void display_stats_menu()
{
    display_main_title(to_upper(PLAYER.get_name_and_title() + " STATISTICS"));
    display_text("Name : " + PLAYER.get_name());
    display_line("Experience : ");
    display_decimal_with_precision(PLAYER.get_experience(), 2);
    display_text(" xp");
    display_line("Critic success(es) : ");
    display_decimal_with_precision(PLAYER.get_nb_critic_successes(), 2);
    display_line("\n");
    display_line("Total throws : ");
    display_decimal_with_precision(PLAYER.get_nb_throws(), 2);
    display_line("\n");

    // QUIT INSTRUCTIONS
    display_line("\n");
    display_text(stats_menu._instruction + "\n");
}

char show_stats_menu(const Character& player)
{
    PLAYER = player;
    display_stats_menu();

    return get_command_from_user<StatsMenu>(stats_menu, &display_stats_menu);
}