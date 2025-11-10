#include <iostream>
#include "Replacer.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: string1 cannot be empty" << std::endl;
        return 1;
    }

    Replacer replacer(filename, s1, s2);

    if (!replacer.openFiles())
    {
        std::cerr << "Error: Cannot open files" << std::endl;
        return 1;
    }

    if (!replacer.processFiles())
    {
        std::cerr << "Error: Failed to process files" << std::endl;
        replacer.closeFiles();
        return 1;
    }

    replacer.closeFiles();
    return 0;
}
