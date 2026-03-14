#include "Weapon.hpp"

Weapon::Weapon(std::string new_value) : type(new_value)
{
	#ifdef DEBUG
		std::cout << "Weapon constructor called" << std::endl;
	#endif
}

Weapon::~Weapon()
{
	#ifdef DEBUG
		std::cout << "Weapon destructor called" << std::endl;
	#endif
}

void Weapon::setType(std::string new_value)
{
	type = new_value;
}

const std::string& Weapon::getType() const
{
	return type;
}


