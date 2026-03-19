#include "Harl.hpp"

void PrintMsg(std::string msg)
{
	std::cout << msg << std::endl;
}


Harl::Harl() { }
Harl::~Harl() { }

void Harl::debug( void )
{
	PrintMsg("[DEBUG]");
	PrintMsg("I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.");
	PrintMsg("I really do!");
	PrintMsg("");
}

void Harl::info( void )
{
	PrintMsg("[INFO]");
	PrintMsg("I cannot believe adding extra bacon costs more money.");
	PrintMsg("You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!");
	PrintMsg("");
}

void Harl::warning( void )
{
	PrintMsg("[WARNING]");
	PrintMsg("I think I deserve to have some extra bacon for free.");
	PrintMsg("I’ve been coming for years, whereas you started working here just last month.");
	PrintMsg("");
}

void Harl::error( void )
{
	PrintMsg("[ERROR]");
	PrintMsg("This is unacceptable! I want to speak to the manager now.");
	PrintMsg("");
}

void Harl::filter( std::string level )
{
	int i = 0;
	while (i < kMaxNum)
	{
		if (levels_[i] == level)
			break;
		i++;
	}

	switch (i)
	{
		case 0:
			debug(); //[[fallthrough]];
		case 1:
			info(); //[[fallthrough]];
		case 2:
			warning(); //[[fallthrough]];
		case 3:
		{
			error();
			break;
		}
		default:
			PrintMsg("[ Probably complaining about insignificant problems ]");
	}
}