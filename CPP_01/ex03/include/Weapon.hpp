#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iomanip>
#include <iostream>

class Weapon {

	private:
		std::string type;

	public:
		Weapon(std::string new_value);
		~Weapon();

		void setType(std::string new_value);
		const std::string& getType() const;
		
};

#endif