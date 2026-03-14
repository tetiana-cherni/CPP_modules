#include "HumanB.hpp"

// use pointer to obj because it could exist or not (reference can't be nullptr)
// also can change weapon later with setWeapon

HumanB::HumanB(std::string new_name) : name(new_name)
{
	#ifdef DEBUG
		std::cout << "HumanB constructor called" << std::endl;
	#endif
}

HumanB::~HumanB()
{
	#ifdef DEBUG
		std::cout << "HumanB destructor called" << std::endl;
	#endif
}

const std::string& HumanB::getName() const
{
	return (name);
}

void HumanB::setWeapon(Weapon& obj)
{
	weapon_obj = &obj;
}

void HumanB::attack()
{
	if (weapon_obj == nullptr)
	{
		std::cout << getName() << " attacks with their " 
			<< std::endl;
	}
	else
	{
		std::cout << getName() << " attacks with their " 
			<< weapon_obj->getType() << std::endl;
	}
}