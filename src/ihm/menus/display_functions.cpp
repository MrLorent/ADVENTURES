#include "display_functions.hpp"

void clear_console()
{
    system("clear");
}

void display_main_title(const std::string_view main_title)
{
    clear_console();
    std::cout << "|=======| " << main_title << " |=======|\n\n";
}

void display_text(const std::string_view text)
{
    std::cout << text << "\n";
}