#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        
        typedef struct s_level
        {
            std::string level;
            void (Harl::*f)(void);
        } t_level;

        int getLevelIndex(std::string level) const;

    public:
        void complain(std::string level);
        void filterComplain(std::string level);
};

#endif