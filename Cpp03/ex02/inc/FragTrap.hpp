#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
{
    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap &other);
        virtual ~FragTrap();
        FragTrap &operator=(const FragTrap &other);

        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif