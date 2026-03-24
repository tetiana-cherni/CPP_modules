#include <string>
#include <iostream>
#include <iomanip>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;

	//Print adresses
	std::cout << "The memory address of the string variable: " 
			<< std::setw(15) << std::right << &str << std::endl;
	std::cout << "The memory address held by stringPTR: "
			<< std::setw(20) << std::right << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: "
			<< std::setw(20) << std::right << &stringREF << "\n" << std::endl;
	
	//Print values
	std::cout << "The value of the string variable:  "
			<< str << std::endl;
	std::cout << "The value pointed to by stringPTR: "
			<< *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: "
			<< stringREF << std::endl;
	
	return 0;
}