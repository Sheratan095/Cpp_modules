#include "AAnimal.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

AAnimal::AAnimal(): type("Unknown animal")
{
	std::cout << "[ANIMAL] constructor called" << std::endl;

	this->brain = new Brain();
}

AAnimal::AAnimal(const AAnimal &animal)
{
	std::cout << "[ANIMAL] copy constructor called" << std::endl;

	*this = animal;
}

AAnimal::~AAnimal()
{
	delete (this->brain);

	std::cout << "[ANIMAL] destructor called, animal type: " << this->type << std::endl;
}


//--------------------OPERATORS--------------------

AAnimal	&AAnimal::operator=(const AAnimal &rhs)
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

std::string		AAnimal::getType() const
{
	return (this->type);
}

Brain	*AAnimal::getBrain() const
{
	return (this->brain);
}


//--------------------METHODS--------------------


void	AAnimal::makeSound() const
{
	std::cout << "[ANIMAL] unknown animal sound" << std::endl;
}
