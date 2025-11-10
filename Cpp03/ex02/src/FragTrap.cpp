#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " is stereoboosted!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap " << _name << " creates an energetic copy of itself!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " disassembles with a final high five!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (_energyPoints == 0)
    {
        std::cout << "FragTrap " << _name << " is too tired for epic moves!" << std::endl;
        return;
    }
    if (_hitPoints == 0)
    {
        std::cout << "FragTrap " << _name << " can't attack while broken!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " epic attack on " << target 
              << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " enthusiastically requests high fives from everyone!" << std::endl;
}