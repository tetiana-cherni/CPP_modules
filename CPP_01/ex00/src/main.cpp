#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie *zo = nullptr;

	zo = newZombie("Heap_zombie");
	if (!zo)
		return 1;
	zo->announce();
	delete zo;

	std::cout << std::endl;

	randomChump("Stack_zombie");

	return 0;
}