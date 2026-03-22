// https://www.geeksforgeeks.org/software-engineering/try-catch-block-in-programming/
// https://uvdn7.github.io/cpp-exception-1/
// https://medium.com/@sachinklocham/c-zero-cost-abstractions-what-they-really-mean-myth-or-reality-with-godbolt-proofs-dc2910c478e3
// https://en.cppreference.com/w/cpp/language/Zero-overhead_principle.html

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	Zombie	*zo = nullptr;
	int		N = -3;

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
		std::cerr << "Error: Couldn't allocate memory " << error.what() << std::endl;
		return 1;
	}

	return 0;
}