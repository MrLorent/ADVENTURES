#include <vector>

#include "string_tools.hpp"
#include "user_input.hpp"
#include "display_functions.hpp"

#include "monster_initialization.hpp"
#include "fight.hpp"

namespace {
std::string MONSTER_NAME = "UNKNOWN";
} // namespace

void display_fight_menu();
void fight(const std::vector<Character>& combatants);

void display_fight_menu()
{
    display_main_title("FIGHT AGAINST " + MONSTER_NAME);
}

void fight_against_monster(const Character& player)
{
    Character monster = create_random_monster();
    MONSTER_NAME      = to_upper(monster.get_name());
    fight(std::vector<Character>(2) = {player, monster});
}

void fight(const std::vector<Character>& combatants)
{
    short unsigned int attacker                 = 0;
    std::vector<int>   combatants_health_points = {combatants[0].get_health(), combatants[1].get_health()};

    while (combatants_health_points[0] > 0 && combatants_health_points[1] > 0) {
        display_fight_menu();
        display_text(combatants[attacker].get_name() + " attacks !");

        const int defender = (attacker == 0 ? 1 : 0);
        const int damages  = 5;
        combatants_health_points[defender] -= damages;
        if (combatants_health_points[defender] < 0)
            combatants_health_points[defender] = 0;

        display_text(combatants[defender].get_name() + " has " + std::to_string(combatants_health_points[defender]) + " health points left.");

        wait_for_any_key_pressed();
        attacker = defender;
    }
}