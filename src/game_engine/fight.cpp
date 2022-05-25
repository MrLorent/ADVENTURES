#include "user_input.hpp"

#include "monster_initialization.hpp"
#include "fight.hpp"

void fight_against_monster(/*const Character& player*/)
{
    Character monster = create_random_monster();
    monster.introduce_themself();
    //int       player_health_points = player.get_health();
    wait_for_any_key_pressed();
}