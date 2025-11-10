#include <iostream>

class	Zombie
{
	private:
		std::string	Name;
	
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce();
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
