#include "Harl.hpp"

void PrintMsg(std::string msg)
{
	std::cout << msg << std::endl;
}


// Syntax

// return_type (ClassName::*pointer_name)(argument_types) = &ClassName::member_function;
// where:

// return_type: is the return type of the member function of the class.
// ClassName: is the name of the class to which the member function belongs.
// *pointer_name: is the name of the function pointer variable.
// argument_types: are the types of the arguments accepted by the member function.
// &ClassName::member_function: is the address of the member function being assigned to the function pointer.

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

void Harl::complain( std::string level )
{
	t_level_complain arr[4] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	for (int i = 0; i < kNumCompl; i++)
	{
		if (arr[i].level_ == level)
		{
			(this->*arr[i].ptrToMemberFn)();
			return ;
		}
	}
	PrintMsg("Please use one argument from this list: DEBUG, INFO, WARNING, ERROR");
}