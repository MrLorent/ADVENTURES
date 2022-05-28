#include <vector>

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
void fight(Character& player, const Character& monster);

void display_fight_menu()
{
    display_main_title("FIGHT AGAINST " + MONSTER_NAME);
}

void fight_against_monster(Character& player)
{
    Character monster = create_random_monster();
    MONSTER_NAME      = to_upper(monster.get_name());
    fight(player, monster);
}

void fight(Character& player, const Character& monster)
{
    std::vector<Character> combatants               = {player, monster};
    short unsigned int     attacker                 = 0;
    std::vector<int>       combatants_health_points = {combatants[0].get_health(), combatants[1].get_health()};

    while (combatants_health_points[0] > 0 && combatants_health_points[1] > 0) {
        display_fight_menu();
        display_text(combatants[attacker].get_name_and_title() + " attacks !");

        const int defender = (attacker == 0 ? 1 : 0);

        const int  attack_state  = combatants[attacker].attacks();
        float      damages       = 0;
        const bool attack_dodged = combatants[defender].dodges();

        if (attack_state == static_cast<int>(Attack_states::Critic_failure)) {
            display_text("Unfortunatly, it's a critic failure...");
        }
        else if (attack_state == static_cast<int>(Attack_states::Critic_success)) {
            display_text("Incredible ! It's a critic success !");
            damages = combatants[attacker].get_damages() * 2;
        }
        else if (attack_dodged) {
            display_text("It's a success !");
            display_text("Unfortunatly, " + combatants[defender].get_name_and_title() + " dodges the attack...");
        }
        else {
            display_text("It's a success !");
            damages = combatants[attacker].get_damages();
        }
        combatants_health_points[defender] -= damages;

        if (combatants_health_points[defender] < 0)
            combatants_health_points[defender] = 0;

        display_text("\n" + combatants[defender].get_name_and_title() + " takes " + std::to_string(damages) + " damages,");
        display_text("and has " + std::to_string(combatants_health_points[defender]) + " health points left.\n");

        wait_for_any_key_pressed();
        attacker = defender;
    }

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