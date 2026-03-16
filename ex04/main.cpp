#include "Replace.hpp"

//filename, s1, s2
int main(int argc, char **argv)
{
	if (argc != 4)
	{
		ErrorMsg("Invalid input. Expected filename, s1 and s2.");
		return 1;
	}
	ReplaceInFile	replace_in_obj(argv[1], argv[2], argv[3]);
	if(replace_in_obj.replace())
		return 1;
	return 0;
}
