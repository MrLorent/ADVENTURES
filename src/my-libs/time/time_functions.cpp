#include <time.h>
#include "time_functions.hpp"

float convert_float_in_minutes(const float signed_time)
{
    float time    = std::abs(signed_time);
    int   minutes = static_cast<int>(time);
    float seconds = (time - minutes) * 60.f / 100.f;
    seconds       = int(seconds * 100) / 100.f;

    return float(minutes) + seconds;
}

std::string get_float_without_zeros(const float decimal)
{
    std::string clean_decimal = std::to_string(decimal);

    while (clean_decimal.at(clean_decimal.size() - 1) == '0') {
        clean_decimal.pop_back();
    }

    return clean_decimal;
}