#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		Weapon*		weapon_obj = nullptr;
		std::string	name_;

	public:
		HumanB(std::string new_name);
		~HumanB();

		const std::string& getName() const;
		void setWeapon(Weapon& obj);
		void attack();

};

#endif