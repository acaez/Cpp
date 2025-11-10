#include <iostream>
#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special"
              << "ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put "
              << "enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for "
              << "years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

int Harl::getLevelIndex(std::string level) const
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            return i;
    }
    return -1;
}

void Harl::complain(std::string level)
{
    t_level levels[] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
    };

    for (int i = 0; i < 4; i++)
    {
        if (levels[i].level == level)
            (this->*levels[i].f)();
    }
}

void Harl::filterComplain(std::string level)
{
    int levelIndex = getLevelIndex(level);
    
    switch (levelIndex)
    {
        case 0:
            debug();
            [[fallthrough]];
        case 1:
            info();
            [[fallthrough]];
        case 2:
            warning();
            [[fallthrough]];
        case 3:
            error();
            break;
        default:
            std::cout << "Probably complaining about insignificant problems" << std::endl;
    }
}
