#include "Zombie.hpp"

int main( void )
{
	Zombie *zombie = newZombie("Zomviee");
	
	zombie->announce();

	randomChump("we");

	delete zombie;
}
