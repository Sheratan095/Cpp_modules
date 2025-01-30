#include "Ice.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

Ice::Ice() : AMateria("ice")
{
	std::cout << "[ICE] constructor called" << std::endl;
}

Ice::Ice(Ice const &ice) : AMateria(ice.getType())
{
	std::cout << "[ICE] copy constructor called" << std::endl;

	*this = ice;
}

Ice::~Ice()
{
	std::cout << "[ICE] destructor called" << std::endl;
}

//--------------------OPERATORS--------------------


Ice	&Ice::operator=(Ice const &rhs)
{
	std::cout << "[ICE] assignment operator called" << std::endl;

	if (&rhs == this)
		return (*this);

	AMateria::operator=(rhs);

	return (*this);
}	

//--------------------METHODS--------------------


void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice		*Ice::clone() const
{
	return (new Ice(*this));
}
