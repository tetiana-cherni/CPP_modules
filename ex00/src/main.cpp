// try catch for allocation error

#include "Zombie.hpp"

int main()
{
	Zombie *zo = nullptr;

	zo = newZombie("Heap_zombie");
	if (!zo)
		return 1;
	zo->announce();
	delete zo;

	randomChump("Stack_zombie");

	return 0;
}