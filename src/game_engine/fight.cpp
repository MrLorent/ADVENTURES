#include <vector>
#include <cassert>

#include "string_tools.hpp"
#include "user_input.hpp"
#include "display_functions.hpp"

#include "attack_states.hpp"
#include "monster_initialization.hpp"
#include "fight.hpp"

namespace {
std::string MONSTER_NAME = "UNKNOWN";
} // namespace

void display_fight_menu();
void display_monster_presentation();
void fight(Character& player, const Character& monster);

void display_fight_menu()
{
    display_main_title("FIGHT AGAINST " + MONSTER_NAME);
}

void display_monster_presentation(Character monster)
{
    display_main_title(MONSTER_NAME);

    display_text("You come accross a " + monster.get_name() + " !");
    display_line("Experience : " + std::to_string(monster.get_experience()));
    display_text(" xp");
    display_line("Total health points : " + std::to_string(monster.get_health()));
    display_text(" hp\n");

    display_text("Get ready !");

    wait_for_any_key_pressed();
}

void fight_against_monster(Character& player, Difficulty game_difficulty)
{
    Character monster = create_random_monster(game_difficulty);
    MONSTER_NAME      = to_upper(monster.get_name());

    display_monster_presentation(monster);

    fight(player, monster);
}

void fight(Character& player, const Character& monster)
{
    std::vector<Character> combatants               = {player, monster};
    short unsigned int     attacker                 = 0;
    std::vector<float>     combatants_health_points = {float(combatants[0].get_health()), float(combatants[1].get_health())};

    while (combatants_health_points[0] > 0 && combatants_health_points[1] > 0) {
        display_fight_menu();

        const int defender = (attacker == 0 ? 1 : 0);

        const int  attack_state  = combatants[attacker].attacks();
        float      damages       = 0;
        const bool attack_dodged = combatants[defender].dodges();

        if (attack_state == static_cast<int>(Attack_states::Critic_failure)) {
            display_text(combatants[attacker].get_name() + " attacks and...\nUnfortunatly, it's a critic failure...");
        }
        else if (attack_state == static_cast<int>(Attack_states::Critic_success)) {
            display_text(combatants[attacker].get_name() + " attacks and...\nIncredible ! It's a critic success !");
            damages = combatants[attacker].get_damages() * 2;
        }
        else if (attack_dodged) {
            display_text(combatants[attacker].get_name() + " attacks and...\nUnfortunatly, " + combatants[defender].get_name() + " dodges the attack...");
        }
        else {
            display_text(combatants[attacker].get_name() + " attacks and...\nIt's a success !");
            damages = combatants[attacker].get_damages();
        }
        combatants_health_points[defender] -= damages;

        if (combatants_health_points[defender] < 0)
            combatants_health_points[defender] = 0;

        display_line("\n" + combatants[defender].get_name() + " takes ");
        display_decimal_with_precision(damages, 2);
        display_text(" damages.");
        display_line("Them has ");
        display_decimal_with_precision(combatants_health_points[defender], 2);
        display_text(" health points left.\n");

        wait_for_any_key_pressed();
        attacker = defender;
    }

    player.add_nb_critic_successes(combatants[0].get_nb_critic_successes());
    player.add_nb_throws(combatants[0].get_nb_throws());

    if (attacker == 1) {
        display_main_title("VICTORY");
        display_text("You won !");
        display_text(player.get_name_and_title() + " gain " + std::to_string(monster.get_experience() * 0.3) + " xp.\n");
        player.add_experience(monster.get_experience() * 0.3);
        wait_for_any_key_pressed();
    }
    else {
        display_main_title("DEFEAT");
        display_text("You loose...");
        display_text("Maybe next time ?\n");
        wait_for_any_key_pressed();
    }
}