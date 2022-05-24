#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <json/json.h>

#include "random.hpp"
#include "fight_menu.hpp"

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

void get_random_monster()
{
    const float        t       = rand<float>(0.f, 1.f);
    std::vector<float> lambdas = {1.f, 2.f, 3.f};

    const float random_rank = generalized_erlang(t, lambdas);
    const int   rank        = (LIST_OF_MONSTERS.size() - 1) * random_rank / 5.f;

    std::cout << LIST_OF_MONSTERS[rank]._name << "\n"
              << LIST_OF_MONSTERS[rank]._experience << "xp\n";
}