#include "Ice.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

AMateria::AMateria(const std::string &type) : type("ice")
{
	std::cout << "[ICE] constructor called type= " << this->type << std::endl;
}

AMateria::AMateria(AMateria const & aMateria)
{
	std::cout << "[AMateria] copy called type= " << this->type << std::endl;

	*this = aMateria;
}

AMateria::~AMateria()
{
	std::cout << "[AMateria] destructor called type= " << this->type << std::endl;
}

//--------------------OPERATORS--------------------


AMateria	&AMateria::operator=(AMateria const &rhs)
{
	if (&rhs == this)
		return (*this);

	this->type = rhs.getType();

	return (*this);
}

//--------------------GETTERS-SETTERS--------------------


std::string const	&AMateria::getType() const
{
	return (this->type);
}

//--------------------METHODS--------------------


void	AMateria::use(ICharacter &target)
{
	std::cout << "[AMateria] type= " << this->type << " is used by: " << target->getName() << std::endl;
}
