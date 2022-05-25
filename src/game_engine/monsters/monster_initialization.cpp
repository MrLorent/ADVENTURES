#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cassert>

#include <json/json.h>

#include "random.hpp"
#include "character_initialization.hpp"
#include "monster_initialization.hpp"

struct Monster {
    const std::string _name;
    const int         _experience;

    Monster()
        : _name("unknown"), _experience(0)
    {
    }

    Monster(const std::string name, const int experience)
        : _name(name), _experience(experience)
    {
    }
};

std::vector<Monster> load_monsters();
Monster              get_random_monster();

const std::vector<Monster> LIST_OF_MONSTERS = load_monsters();

std::vector<Monster> load_monsters()
{
    std::vector<Monster> list_of_monsters;

    try {
        Json::Value   monsters_json;
        Json::Reader  reader;
        std::ifstream json_file("assets/monsters.json", std::ifstream::binary);
        json_file >> monsters_json;

        for (auto monster : monsters_json["monsters"]) {
            list_of_monsters.push_back(Monster(monster.get("name", "unknown").asString(), monster.get("xp", 0).asInt()));
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return list_of_monsters;
}

Monster get_random_monster()
{
    const int          MAX_RANK = LIST_OF_MONSTERS.size() - 1;
    const float        t        = rand<float>(0.f, 1.f);
    std::vector<float> lambdas  = {1.f, 2.f};

    const float X    = generalized_erlang(t, lambdas);
    const int   rank = std::clamp(int(MAX_RANK * X / 5.f), 0, MAX_RANK);

    return LIST_OF_MONSTERS[rank];
}

Character create_random_monster()
{
    Character monster       = create_random_character();
    Monster   monster_infos = get_random_monster();

    monster.set_name(monster_infos._name);

    return monster;
}