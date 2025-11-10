#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <string>
# include <fstream>

class Replacer
{
    private:
        std::string     filename;
        std::string     s1;
        std::string     s2;
        std::ifstream   inFile;
        std::ofstream   outFile;

        std::string     replaceInString(std::string line) const;

    public:
        Replacer(const std::string& filename, const std::string& s1, const std::string& s2);
        bool    openFiles();
        bool    processFiles();
        void    closeFiles();
};

#endif