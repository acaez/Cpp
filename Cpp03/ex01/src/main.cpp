#include "ScavTrap.hpp"

void displayStatus(const ClapTrap& trap) 
{
    std::cout << "Status | Énergy: " << trap.getEnergyPoints() << ", HP: " << trap.getHitPoints() << ", Dégâts: " << trap.getAttackDamage() << std::endl;
}

int main()
{
    std::cout << "\n=== Test de création ===" << std::endl;
    ScavTrap scav("SC4V-TP");
    displayStatus(scav);

    std::cout << "\n=== Test d'héritage et polymorphisme ===" << std::endl;
    ClapTrap& ref = scav;
    ref.attack("Target");

    std::cout << "\n=== Test de guardGate ===" << std::endl;
    scav.guardGate();

    std::cout << "\n=== Test des attaques ===" << std::endl;
    scav.attack("Bandit");
    displayStatus(scav);
    
    std::cout << "\n=== Test des dégâts ===" << std::endl;
    scav.takeDamage(30);
    displayStatus(scav);
    
    std::cout << "\n=== Test des réparations ===" << std::endl;
    scav.beRepaired(20);
    displayStatus(scav);
    
    std::cout << "\n=== Test de destruction ===" << std::endl;
    
    return 0;
}