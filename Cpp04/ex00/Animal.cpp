#include "Animal.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

Animal::Animal(): type("Unknown animal")
{
	std::cout << "[ANIMAL] constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	*this = animal;

	std::cout << "[ANIMAL] copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "[ANIMAL] destructor called, animal type: " << this->type << std::endl;
}


//--------------------OPERATORS--------------------

Animal	&Animal::operator=(const Animal &rhs)
{
	std::cout << "[ANIMAL] assignment operator called" << std::endl;

	if (&rhs == this)
		return (*this);

	this->type = rhs.getType();

	return (*this);
}


//--------------------GETTERS-SETTERS--------------------

std::string		Animal::getType() const
{
	return (this->type);
}


//--------------------METHODS--------------------


void	Animal::makeSound() const
{
	std::cout << "[ANIMAL] unknown animal sound" << std::endl;
}
