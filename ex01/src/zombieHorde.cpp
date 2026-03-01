#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombie[i].SetName(name);
	}
	return zombie;
}

/*
Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		if (i % 2)
		{
			std::string new_name = name + "_1";
			zombie[i].SetName(new_name);
		}
		else
			zombie[i].SetName(name);
	}
	return zombie;
} */