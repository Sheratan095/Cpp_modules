#include "Brain.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

Brain::Brain()
{
	std::cout << "[BRAIN] constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	*this = brain;

	std::cout << "[BRAIN] copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "[BRAIN] destructor called" << std::endl;
}


//--------------------OPERATORS--------------------

Brain	&Brain::operator=(const Brain &rhs)
{
	std::cout << "[BRAIN] copy assignment operator called" << std::endl;

	if (this != &rhs)
		return (*this);

	for (int i = 0; i < this->ideasCount; i++)
		this->ideas[i] = rhs.getIdea(i);

	return (*this);
}


//--------------------GETTERS-SETTERS--------------------

std::string		Brain::getIdea(int index) const
{
	if (index < 0 || index >= this->ideasCount)
		return ("");

	return (this->ideas[index]);
}
