#include "AMateria.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

AMateria::AMateria(const std::string &type) : type(type)
{
	std::cout << "[AMATERIA] constructor called type= " << this->type << std::endl;
}

AMateria::AMateria(AMateria const & aMateria)
{
	std::cout << "[AMATERIA] copy constructor called type= " << this->type << std::endl;

	*this = aMateria;
}

AMateria::~AMateria()
{
	std::cout << "[AMATERIA] destructor called type= " << this->type << std::endl;
}

//--------------------OPERATORS--------------------


AMateria	&AMateria::operator=(AMateria const &rhs)
{
	std::cout << "[AMATERIA] asassignment operator called type= " << this->type << std::endl;

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
	std::cout << "[AMATERIA] type= " << this->type << " is used by: " << target.getName() << std::endl;
}
