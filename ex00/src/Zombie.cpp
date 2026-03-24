#include "Zombie.hpp"

Zombie::Zombie()
{
#ifdef DEBUG
	std::cout << "Zombie constructor called" << std::endl;
#endif
}

Zombie::~Zombie()
{
#ifdef DEBUG
	std::cout << "Zombie destructor called" << std::endl;
#endif

	std::cout << "Destructor called for: " << name_ << std::endl;
}

void Zombie::SetName(const std::string &name)
{
	name_ = name;
}

void Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
