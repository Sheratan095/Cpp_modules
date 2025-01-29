#include "Cat.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

Cat::Cat(): Animal()
{
	this->type = "Cat";

	std::cout << "[CAT] constructor called" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	*this = cat;

	std::cout << "[CAT] copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "[CAT] destructor called" << std::endl;
}


//--------------------OPERATORS--------------------

Cat	&Cat::operator=(const Cat &rhs)
{
	std::cout << "[CAT] assignation operator called" << std::endl;

	if (&rhs == this)
		return (*this);

	this->type = rhs.getType();

	return (*this);
}

//--------------------METHODS--------------------


void	Cat::makeSound() const
{
	std::cout << "[CAT] meow meow" << std::endl;
}
