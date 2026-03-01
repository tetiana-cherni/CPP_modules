#include "Zombie.hpp"
// This function creates a zombie, names it, 
// and returns it so you can use it outside 
// of the function scope.

Zombie* newZombie(std:: string name)
{
	Zombie *zombie = new (std::nothrow) Zombie;

	if (!zombie)
	{
		std::cerr << "Error: Couldn't allocate memory" << std::endl;
		return nullptr;
	}
	zombie->SetName(name);
	return (zombie);
}
