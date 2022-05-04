#include <iostream>

#include "random.hpp"
#include "characters.hpp"

int main()
{
    Knight   the_knight("Gontrand");
    Archer   the_archer("Theophile");
    Magician the_magician("Ivancéliandre");

    the_knight.introduce_themself();
    the_archer.introduce_themself();
    the_magician.introduce_themself();
}