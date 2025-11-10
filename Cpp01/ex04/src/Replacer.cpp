#include "Replacer.hpp"

Replacer::Replacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {}

bool Replacer::openFiles()
{
    inFile.open(filename.c_str());
    if (!inFile.is_open())
        return false;

    std::string outFilename = filename + ".replace";
    outFile.open(outFilename.c_str());
    if (!outFile.is_open())
    {
        inFile.close();
        return false;
    }
    return true;
}

std::string Replacer::replaceInString(std::string line) const
{
    std::string result;
    size_t startPos = 0;
    size_t findPos;

    while ((findPos = line.find(s1, startPos)) != std::string::npos)
    {
        result.append(line, startPos, findPos - startPos);
        result.append(s2);
        startPos = findPos + s1.length();
    }
    result.append(line, startPos, line.length() - startPos);
    return result;
}

bool Replacer::processFiles()
{
    std::string line;
    
    while (std::getline(inFile, line))
    {
        outFile << replaceInString(line);
        if (!inFile.eof())
            outFile << std::endl;
    }
    return true;
}

void Replacer::closeFiles()
{
    if (inFile.is_open())
        inFile.close();
    if (outFile.is_open())
        outFile.close();
}
