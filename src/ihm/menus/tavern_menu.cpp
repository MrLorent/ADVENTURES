#include <vector>

#include "random.hpp"
#include "casts.hpp"
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
        std::string option = " ";
        option += tavern_menu._commands.at(command);
        option += ". " + tavern_menu._labels.at(command);
        display_line(option);

        if (std::tolower(tavern_menu._commands.at(command)) != std::tolower(tavern_menu._last_command)) {
            display_line(" (Duration : ");
            display_decimal_with_precision(quests_durations.at(quest_count), 2);
            display_line(" min)\n");
            quest_count++;
        }
        else {
            display_text("\n");
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