#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include "Gettext.h"

namespace Utils
{
int introduction()
{
    std::cout << std::endl;
    std::cout << _("For an optimal experience, set your window size to 60x20 and zoom a little bit!") << std::endl;
    std::cout << std::endl;

    std::cout << _("Select the difficulty:") << std::endl;
    std::cout << _("1 - Easy") << std::endl;
    std::cout << _("2 - Medium (Default)") << std::endl;
    std::cout << _("3 - Hard") << std::endl;
    std::cout << std::endl;

    int selection = std::cin.get() - 48;

    switch (selection)
    {
    case 1:
        return 120;
    case 2:
        return 80;
    case 3:
        return 50;
    default:
        break;
    }
    return 80;
}

void gameLost()
{
    std::cout << std::endl;
    std::cout << _("YOU STEPPED ON YOURSELF AND DIED!") << std::endl;
    std::cout << std::endl;

    std::cout << _("You played SNAKE - by Luca Errani") << std::endl;
    std::cout << _("Feel free to contribute at https://github.com/luco5826/snake") << std::endl;
}
} // namespace Utils

#endif