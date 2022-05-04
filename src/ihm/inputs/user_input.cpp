#include "user_input.hpp"

void wait_for_any_key_pressed()
{
    std::cout << "\nPlease press any key to continue.\n";
    std::cin.ignore();
    std::cin.get();
}