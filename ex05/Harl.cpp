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

Harl::Harl()
{
	
}

Harl::~Harl()
{

}

void Harl::debug( void )
{
	PrintMsg("Debug");
}

void Harl::info( void )
{
	PrintMsg("Info");
}

void Harl::warning( void )
{
	PrintMsg("Warning");
}

void Harl::error( void )
{
	PrintMsg("Error");
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
		}
	}
}