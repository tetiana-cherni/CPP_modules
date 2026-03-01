#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <new>

class Zombie {
	private:
		std::string name_;

	public:
	
		Zombie();
		~Zombie();

	//setter
		void SetName(std::string name);
	//getter
		const std::string& name() const;

	//utils
		void announce(void);
};




#endif