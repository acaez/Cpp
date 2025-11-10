#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void displayStatus(const ClapTrap& trap) 
{
    std::cout << "Status | Name: " << trap.getName()
              << ", Energy: " << trap.getEnergyPoints() 
              << ", HP: " << trap.getHitPoints() 
              << ", Damage: " << trap.getAttackDamage() << std::endl;
}

int main()
{
    std::cout << "\n=== Test des trois types de robots ===" << std::endl;
    ClapTrap clap("CL4P");
    ScavTrap scav("SC4V");
    FragTrap frag("FR4G");

    std::cout << "\n=== Initial State ===" << std::endl;
    displayStatus(clap);
    displayStatus(scav);
    displayStatus(frag);

    std::cout << "\n=== Test des capacités spéciales ===" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();

    std::cout << "\n=== Test des attaques ===" << std::endl;
    clap.attack("Bandit");
    scav.attack("Skuuh");
    frag.attack("Harch");

    std::cout << "\n=== Test des dégâts et réparations ===" << std::endl;
    frag.takeDamage(50);
    displayStatus(frag);
    frag.beRepaired(30);
    displayStatus(frag);

    std::cout << "\n=== Les destructeurs sont appelés dans l'ordre inverse ===" << std::endl;
    return 0;
}