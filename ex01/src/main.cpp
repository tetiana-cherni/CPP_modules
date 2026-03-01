#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	Zombie	*zo = nullptr;
	int		N = 3;

	try {
		zo = zombieHorde(N, "heap_zombie");
		for (int i = 0; i < N; i++)
		{
			// std::cout << "Zombie number = " << i << ":" << std::endl;
			zo[i].announce();
		}
		delete[] zo;
	} 
	catch (const std::bad_alloc& error)
	{
		std::cerr << "Error: Couldn't allocate memory" << error.what() << std::endl;
		return 1;
	}
	return 0;
}