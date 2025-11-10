#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        std::cout << "=== Profile Police (toujours armé) ===" << std::endl;
        Weapon pol = Weapon("M4");
        HumanA jhon("Jhon", pol);
        jhon.attack();
        pol.setType("AWP");
        jhon.attack();
    }
    {
        std::cout << "\n=== Profile terroriste (sans arme) ===" << std::endl;
        HumanB mani("Mani");
        mani.attack();
    }
    {
        std::cout << "\n=== Profile terroriste (avec arme) ===" << std::endl;
        Weapon ter = Weapon("AK-47");
        HumanB wodi("Wodi");
        wodi.setWeapon(ter);
        wodi.attack();
        ter.setType("MAC-10");
        wodi.attack();
    }
    return 0;
}
