#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		PrintMsg("Please use one argument from this list: DEBUG, INFO, WARNING, ERROR");
		return (1);
	}
	Harl obj;
	obj.filter(argv[1]);
	return (0);
}