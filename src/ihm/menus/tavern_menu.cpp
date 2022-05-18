#include <vector>

#include "random.hpp"
#include "time_functions.hpp"
#include "display_functions.hpp"
#include "menu_commons.hpp"
#include "tavern_menu.hpp"

// LOCAL GLOBALS
namespace {
constexpr short unsigned nb_quests = 3;
std::vector<float>       quests_durations(nb_quests, 0.f);
} // namespace

// PROTOTYPES
void display_tavern_menu();

void display_tavern_menu()
{
    short unsigned int quest_count = 0;
    display_main_title("TAVERN");
    display_text(tavern_menu._instruction);

    for (auto command : tavern_menu._options) {
        std::string option_text = " ";
        option_text += tavern_menu._commands.at(command);
        option_text += ". " + tavern_menu._labels.at(command);

        if (std::tolower(tavern_menu._commands.at(command)) != std::tolower(tavern_menu._last_command)) {
            option_text += " (Duration : " + get_float_without_zeros(quests_durations.at(quest_count)) + " min)";
            quest_count++;
        }
        else {
            option_text += "\n";
        }

        display_text(option_text);
    }
}

char show_tavern_menu()
{
    // GET THREE RANDOM DURATION FOR THE QUESTS
    float duration = 5.f;

    for (short unsigned int i = 0; i < nb_quests; i++) {
        quests_durations[i] = convert_float_in_minutes(box_muller(duration, 2.f));
        duration += 5;
    }

    display_tavern_menu();

    return get_command_from_user<TavernMenu>(tavern_menu, &display_tavern_menu);
}