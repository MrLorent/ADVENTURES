#pragma once
#define DISPLAY_FUNCTIONS_HPP

#include <iostream>

void clear_console();
void display_main_title(const std::string_view main_title);
void display_text(const std::string_view text);
void display_line(const std::string_view line);
void display_decimal_with_precision(const float number, const int precision);