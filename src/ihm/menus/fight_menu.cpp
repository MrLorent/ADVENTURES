#include <iostream>
#include <fstream>

#include <json/json.h>

#include "fight_menu.hpp"

const std::vector<Monster> LIST_OF_MONSTERS = load_monsters();

std::vector<Monster> load_monsters()
{
    std::vector<Monster> list_of_monsters;

    try {
        Json::Value   monsters_json;
        Json::Reader  reader;
        std::ifstream json_file("assets/monsters.json", std::ifstream::binary);

        json_file >> monsters_json;

        std::cout << monsters_json;

        for (auto monster : monsters_json["monsters"]) {
            list_of_monsters.push_back(Monster(monster.get("name", "unknown").asString(), monster.get("exp", 0).asInt()));
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return list_of_monsters;
}