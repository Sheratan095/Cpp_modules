
#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::Zombie( std::string name ): name(name)
{}

Zombie::~Zombie( void )
{
	std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& newName)
{
	this->name = newName;
}

std::string Zombie::getName( void ) const
{
	return (this->name);
}