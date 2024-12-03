#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{}

Weapon::~Weapon()
{}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}

const std::string	&Weapon::getType()
{
	return (this->type);
}
