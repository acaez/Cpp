#include "ClapTrap.hpp"

void displayStatus(const ClapTrap& clap) 
{
    std::cout << "Current status | Energy: " << clap.getEnergyPoints() << ", HP: " << clap.getHitPoints() << std::endl;
}

int main()
{
    std::cout << "\n=== Test de création ===" << std::endl;
    ClapTrap clap("CL4P-TP");
    displayStatus(clap);
    
    std::cout << "\n=== Test des attaques ===" << std::endl;
    clap.attack("Bandit");
    displayStatus(clap);
    clap.attack("Skuuh");
    displayStatus(clap);
    
    std::cout << "\n=== Test des dégâts ===" << std::endl;
    clap.takeDamage(5);
    displayStatus(clap);
    clap.takeDamage(3);
    displayStatus(clap);
    
    std::cout << "\n=== Test des réparations ===" << std::endl;
    clap.beRepaired(4);
    displayStatus(clap);
    clap.beRepaired(2);
    displayStatus(clap);
    
    std::cout << "\n=== Test des limites d'énergie ===" << std::endl;
    for (int i = 0; i < 8; ++i) 
    {
        std::cout << "\nEssai d'attaque " << i + 1 << ":" << std::endl;
        clap.attack("Target");
        displayStatus(clap);
    }
    
    std::cout << "\n=== Test de destruction ===" << std::endl;
    clap.takeDamage(20);
    clap.attack("Someone");
    clap.beRepaired(5);
    
    return 0;
}