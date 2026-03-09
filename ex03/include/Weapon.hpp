#ifndef WEAPON_HPP
# include <string>
#define WEAPON_HPP

Class Weapon {

	private:
		std::string type_;

	public:
		void setType(std::string new_value);
		const std::string& getType() const;
};

#endif