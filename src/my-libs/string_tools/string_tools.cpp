#include "string_tools.hpp"

std::string to_upper(const std::string str)
{
    std::string str_copy(str);

    for (auto& c : str_copy)
        c = toupper(c);

    return str_copy;
}