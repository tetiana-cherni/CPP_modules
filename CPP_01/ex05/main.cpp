#include "Harl.hpp"

int main()
{
	Harl obj;

	obj.complain("DEBUG");
	PrintMsg("");
	obj.complain("INFO");
	PrintMsg("");
	obj.complain("WARNING");
	PrintMsg("");
	obj.complain("ERROR");
	PrintMsg("");
	obj.complain("nnkj");
	
	return 0;
}