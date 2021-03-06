#include "string_tools.hpp"
#include "display_functions.hpp"
#include "user_input.hpp"
#include "random.hpp"

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
    display_decimal_with_precision(PLAYER.get_experience(), 0);
    display_text(" xp");
    display_line("Critic success(es) : ");
    display_decimal_with_precision(PLAYER.get_nb_critic_successes(), 0);
    display_line("\n");
    display_line("Total throws : ");
    display_decimal_with_precision(PLAYER.get_nb_throws(), 0);
    display_line("\n");
    display_line("Next critic expected in : ");
    const float critic_probability = float(PLAYER.get_nb_critic_successes()) / float(PLAYER.get_nb_throws());
    // float       average_throws     = 0;
    // for (int i = 0; i < 100; ++i) {
    //     average_throws += geometric_law(critic_probability);
    // }
    // average_throws = average_throws / 100;
    // int trunc      = average_throws;
    // average_throws = trunc + (average_throws - trunc > 0.5 ? 1 : 0);
    display_decimal_with_precision(critic_probability, 0);
    display_text(" throw(s)");

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