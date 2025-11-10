#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " is constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << " is copied!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " is destroyed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " is out of energy and cannot attack!" << std::endl;
        return;
    }
    if (_hitPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " is broken and cannot attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " special attack " << target << " causing " 
              << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}