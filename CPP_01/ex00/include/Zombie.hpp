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

		void SetName(const std::string& name);

		void announce(void);
};


#endif