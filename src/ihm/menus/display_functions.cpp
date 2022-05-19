#include <iomanip>

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

void display_line(const std::string_view line)
{
    std::cout << line;
}

void display_decimal_with_precision(const float number, const int precision)
{
    std::cout << std::fixed << std::setprecision(precision) << number;
}