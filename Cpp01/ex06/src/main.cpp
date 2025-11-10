#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << "DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }

    std::string validLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    std::string input = argv[1];

    bool validLevel = false;
    for (int i = 0; i < 4; i++)
    {
        if (input == validLevels[i])
        {
            validLevel = true;
            break;
        }
    }

    if (!validLevel)
    {
        std::cout << "[ Invalid level ]" << std::endl;
        std::cout << "Valid levels are: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }

    Harl harl;
    harl.filterComplain(argv[1]);
    
    return 0;
}
