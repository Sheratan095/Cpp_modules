#include "Dog.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

Dog::Dog(): AAnimal()
{
	this->type = "Dog";

	std::cout << "[DOG] constructor called" << std::endl;
}

Dog::Dog(const Dog &dog): AAnimal()
{
	*this = dog;

	std::cout << "[DOG] copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "[DOG] destructor called" << std::endl;
}


//--------------------OPERATORS--------------------

Dog	&Dog::operator=(const Dog &rhs)
{
	std::cout << "[DOG] assignment operator called" << std::endl;

	if (&rhs == this)
		return (*this);

	AAnimal::operator=(rhs);

	return (*this);
}

//--------------------METHODS--------------------


void	Dog::makeSound() const
{
	std::cout << "[DOG] woof Woof" << std::endl;
}
