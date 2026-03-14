#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

// reference beacause it exist always 
// need to know about changes happened in original object

class HumanA {

	private:
		std::string name;
		Weapon&	weapon_obj;

	public:
		HumanA(std::string new_name, Weapon& type);
		~HumanA();

		const std::string& getName() const;
		void attack();

};

#endif