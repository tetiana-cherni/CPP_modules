#include "HumanA.hpp"

HumanA::HumanA(std::string new_name, Weapon& type): name_(new_name), weapon_obj(type)
{
	#ifdef DEBUG
		std::cout << "HumanA constructor called" << std::endl;
	#endif
}

HumanA::~HumanA()
{
	#ifdef DEBUG
		std::cout << "HumanA destructor called" << std::endl;
	#endif
}
const std::string& HumanA::getName() const
{
	return name_;
}

void HumanA::attack()
{
	std::cout << getName() << " attacks with their " 
		<< weapon_obj.getType() << std::endl;
}
