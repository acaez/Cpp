#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap " << _name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << _name << " is copied!" << std::endl;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) 
{
    if (this != &other) 
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot attack!" << std::endl;
        return;
    }
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is broken and cannot attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << " causing " 
              << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already broken!" << std::endl;
        return;
    }
    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot repair!" << std::endl;
        return;
    }
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is broken and cannot repair!" << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << std::endl;
}

std::string ClapTrap::getName() const { return _name; }
unsigned int ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return _attackDamage; }