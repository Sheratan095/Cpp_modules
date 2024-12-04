#include "Zombie.hpp"

int main( void )
{
	int			n = 5;
	std::string	name = "zombie";

	Zombie *horde = zombieHorde(n, name);

	for (int i = 0; i < n; i++)
		horde[i].announce();

	delete[]horde;
}
