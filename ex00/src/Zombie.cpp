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

	std::cout <<"Destructor called for: " << name_ << std::endl;
	// delete();
}

//accessor
void Zombie::SetName(std::string name)
{
	name_ = name;
}

//mutator
const std::string& Zombie::name() const
{
	return name_ ;
}

void Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

