#include "WrongAnimal.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

WrongAnimal::WrongAnimal(): type("Unknown wrong animal")
{
	std::cout << "[WRONGANIMAL] constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	*this = wrongAnimal;

	std::cout << "[WRONGANIMAL] copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WRONGANIMAL] destructor called, wrong animal type: " << this->type << std::endl;
}


//--------------------OPERATORS--------------------

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "[WRONGANIMAL] assignation operator called" << std::endl;

	if (&rhs == this)
		return (*this);

	this->type = rhs.getType();

	return (*this);
}


//--------------------GETTERS-SETTERS--------------------

std::string		WrongAnimal::getType() const
{
	return (this->type);
}


//--------------------METHODS--------------------


void	WrongAnimal::makeSound() const
{
	std::cout << "[WRONGANIMAL] unknown wrong animal sound" << std::endl;
}
