#include <iostream>
#include <fstream>
#include <vector>

#include <json/json.h>

#include "random.hpp"
#include "casts.hpp"
#include "display_functions.hpp"
#include "menu_commons.hpp"
#include "tavern_menu.hpp"

struct Quest {
    const std::string _name;

    Quest()
        : _name("unknown")
    {
    }

    Quest(const std::string name)
        : _name(name)
    {
    }
};

// PROTOTYPES
std::vector<Quest> load_quests();
void               display_tavern_menu();

// LOCAL GLOBALS
namespace {
const std::vector<Quest> LIST_OF_QUESTS = load_quests();

constexpr short unsigned nb_quests = 3;
std::vector<float>       quests_durations(nb_quests, 0.f);
} // namespace

std::vector<Quest> load_quests()
{
    std::vector<Quest> list_of_quests;

    try {
        Json::Value   quests_json;
        std::ifstream json_file("assets/adventures.json", std::ifstream::binary);
        json_file >> quests_json;

        for (auto adventure : quests_json["adventures"]) {
            list_of_quests.push_back(Quest(adventure.get("name", "unknown").asString()));
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return list_of_quests;
}

void display_tavern_menu()
{
    short unsigned int quest_count = 0;
    display_main_title("TAVERN");
    display_text(tavern_menu._instruction);

    for (auto command : tavern_menu._options) {
        std::string option = " ";
        option += tavern_menu._commands.at(command);

        if (std::tolower(tavern_menu._commands.at(command)) != std::tolower(tavern_menu._last_command)) {
            option += ". " + LIST_OF_QUESTS[rand<int>(0, LIST_OF_QUESTS.size() - 1)]._name;
            option += " (Duration : ";
            display_line(option);
            display_decimal_with_precision(quests_durations.at(quest_count), 2);
            display_line(" min)\n");
            quest_count++;
        }
        else {
            option += ". " + tavern_menu._labels.at(command);
            display_text(option + "\n");
        }
    }
}

char show_tavern_menu(float& selected_quest_duration)
{
    // GET THREE RANDOM DURATION FOR THE QUESTS
    float duration = 5.f;

    for (short unsigned int i = 0; i < nb_quests; i++) {
        quests_durations[i] = convert_float_in_minutes(box_muller(duration, 2.f));
        duration += 5;
    }

    display_tavern_menu();

    const char command = get_command_from_user<TavernMenu>(tavern_menu, &display_tavern_menu);

    if (std::tolower(command) != 'q') {
        selected_quest_duration = quests_durations[int(command - '0') - 1];
    }

    return command;
}