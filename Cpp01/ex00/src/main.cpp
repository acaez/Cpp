#include "Zombie.hpp"

int main()
{
    std::cout << "Creating a zombie on the heap..." << std::endl;
    Zombie* heap_zombie = newZombie("Heap");
    heap_zombie->announce();
    std::cout << "This zombie will exist until we delete it" << std::endl;

    std::cout << "\nCreating a zombie on the stack..." << std::endl;
    randomChump("Stack");
    std::cout << "The stack zombie is already destroyed by now!" << std::endl;

    std::cout << "\nNow destroying the heap zombie..." << std::endl;
    delete heap_zombie;
    
    return (0);
}
