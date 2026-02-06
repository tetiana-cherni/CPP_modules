/*
* megaphone - converts arguments to uppercase
*
* Usage examples:
* $>./megaphone "shhhhh... I think the students are asleep..."
* SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
*
* $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
* DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
*
* $>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
* $>
*/

#include <string>
#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		for (char &c : str)
			c = std::toupper(static_cast<unsigned char>(c));
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
