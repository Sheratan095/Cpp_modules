#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("Zomviee");
	
	zombie->announce();


	delete zombie;
}
