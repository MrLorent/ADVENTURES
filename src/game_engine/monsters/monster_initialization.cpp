#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cassert>

#include <json/json.h>

#include "random.hpp"
#include "difficulties.hpp"
#include "character_initialization.hpp"
#include "monster_initialization.hpp"

struct Monster {
    const std::string _name;
    const int         _health_points;
    const int         _experience;

    Monster(const std::string name = "unknown", const int health_points = 1, const int experience = 0)
        : _name(name), _health_points(health_points), _experience(experience)
    {
    }
};

std::vector<Monster> load_monsters();
Monster              get_random_monster(Difficulty game_difficulty);

const std::vector<Monster> LIST_OF_MONSTERS = load_monsters();

std::vector<Monster> load_monsters()
{
    std::vector<Monster> list_of_monsters;

    try {
        Json::Value   monsters_json;
        std::ifstream json_file("assets/monsters.json", std::ifstream::binary);
        json_file >> monsters_json;

        for (auto monster : monsters_json["monsters"]) {
            list_of_monsters.push_back(Monster(monster.get("name", "unknown").asString(), monster.get("hit_points", 1).asInt(), monster.get("xp", 0).asInt()));
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return list_of_monsters;
}

Monster get_random_monster(Difficulty game_difficulty)
{
    const int MAX_RANK = LIST_OF_MONSTERS.size() - 1;
    int       rank     = 0;

    switch (game_difficulty) {
    case Difficulty::Peaceful: {
        const float X = generalized_erlang(2, 2);
        rank          = int(MAX_RANK * X / 20.f);
        rank          = std::clamp(rank, 0, MAX_RANK);
    } break;

    case Difficulty::Easy: {
        const float X = generalized_erlang(1, 5);
        rank          = int(MAX_RANK * X / 20.f);
        rank          = std::clamp(rank, 0, MAX_RANK);
    } break;

    case Difficulty::Normal: {
        const float X = generalized_erlang(1, 10);
        rank          = int(MAX_RANK * X / 20.f);
        rank          = std::clamp(rank, 0, MAX_RANK);
    } break;

    case Difficulty::Hard: {
        const float X = generalized_erlang(1, 15);
        rank          = int(MAX_RANK * X / 20.f);
        rank          = std::clamp(rank, 0, MAX_RANK);
    } break;

    case Difficulty::Impossible: {
        const float X = generalized_erlang(2, 2);
        rank          = MAX_RANK - int(MAX_RANK * X / 20.f);
        rank          = std::clamp(rank, 0, MAX_RANK);
    } break;

    default:
        assert(false && "[Error] game difficulty asked is undefine.");
        break;
    }

    assert((rank >= 0 || rank <= MAX_RANK) && "Rank asked out of range of LIST_OF_MONSTERS");

    return LIST_OF_MONSTERS[rank];
}

Character create_random_monster(Difficulty game_difficulty)
{
    Character monster       = create_random_character();
    Monster   monster_infos = get_random_monster(game_difficulty);

    monster.set_name(monster_infos._name);
    monster.set_health_points(monster_infos._health_points);
    monster.add_experience(monster_infos._experience);

    return monster;
}