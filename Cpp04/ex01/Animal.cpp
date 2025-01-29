#include "Animal.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

Animal::Animal(): type("Unknown animal")
{
	std::cout << "[ANIMAL] constructor called" << std::endl;

	this->brain = new Brain();
}

Animal::Animal(const Animal &animal)
{
	*this = animal;

	std::cout << "[ANIMAL] copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "[ANIMAL] destructor called, animal type: " << this->type << std::endl;

	delete (this->brain);
}


//--------------------OPERATORS--------------------

Animal	&Animal::operator=(const Animal &rhs)
{
	std::cout << "[ANIMAL] assignation operator called" << std::endl;

	if (&rhs == this)
		return (*this);

	this->type = rhs.getType();

	delete (this->brain);
	this->brain = new Brain(*rhs.getBrain());

	return (*this);
}


//--------------------GETTERS-SETTERS--------------------

std::string		Animal::getType() const
{
	return (this->type);
}

Brain	*Animal::getBrain() const
{
	return (this->brain);
}


//--------------------METHODS--------------------


void	Animal::makeSound() const
{
	std::cout << "[ANIMAL] unknown animal sound" << std::endl;
}
