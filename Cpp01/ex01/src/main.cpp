#include "Zombie.hpp"

int main()
{
    int N = 5;
    std::cout << "Creating a horde of " << N << " zombies..." << std::endl;
    
    Zombie* horde = zombieHorde(N, "Horde");
    
    std::cout << "\nMaking each zombie announce itself:" << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }

    std::cout << "\nDestroying the horde..." << std::endl;
    delete[] horde;
    return (0);
}
