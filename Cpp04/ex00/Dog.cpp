#include "Dog.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

Dog::Dog(): Animal()
{
	this->type = "Dog";

	std::cout << "[DOG] constructor called" << std::endl;
}

Dog::Dog(const Dog &dog): Animal()
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
	std::cout << "[DOG] assignation operator called" << std::endl;

	if (&rhs == this)
		return (*this);

	Animal::operator=(rhs);

	return (*this);
}

//--------------------METHODS--------------------


void	Dog::makeSound() const
{
	std::cout << "[DOG] woof Woof" << std::endl;
}
