#include "Zombie.hpp"

int main()
{
	int n = 5;

	std::string name = "zombie";

	Zombie *horde = zombieHorde(n, name);

	delete[]horde;
}
