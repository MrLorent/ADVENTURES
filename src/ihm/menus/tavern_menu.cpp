#include <vector>

#include "random.hpp"
#include "display_functions.hpp"
#include "tavern_menu.hpp"

void display_tavern_menu(const std::vector<float>& durations);

void display_tavern_menu(const std::vector<float>& durations)
{
    short unsigned int quest_count = 0;
    display_main_title("TAVERN");
    display_text(tavern_menu._instruction);

    for (auto command : tavern_menu._options) {
        std::string option_text = " ";
        option_text += tavern_menu._commands.at(command);
        option_text += ". " + tavern_menu._labels.at(command);

        if (std::tolower(tavern_menu._commands.at(command)) != std::tolower(tavern_menu._last_command)) {
            option_text += " (Duration : " + std::to_string(durations.at(quest_count)) + " min)";
            quest_count++;
        }

        display_text(option_text);
    }
}

void show_tavern_menu()
{
    const short unsigned int NB_QUESTS = 3;
    std::vector<float>       quests_durations(NB_QUESTS, 0.f);
    float                    duration = 5.f;

    for (short unsigned int i = 0; i < NB_QUESTS; i++) {
        quests_durations[i] = box_muller(duration, 2.f);
        duration += 5;
    }

    display_tavern_menu(quests_durations);
}