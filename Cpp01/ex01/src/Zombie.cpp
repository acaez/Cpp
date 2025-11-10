#include "Zombie.hpp"

Zombie::Zombie() : Name("") {}

Zombie::Zombie(std::string name) : Name(name) {}

Zombie::~Zombie()
{
	std::cout << Name << " is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	Name = name;
}
