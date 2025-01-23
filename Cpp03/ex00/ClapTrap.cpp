
#include "ClapTrap.hpp"

// default constructor
ClapTrap::ClapTrap()
	: name("DEFAULT NAME"),
	  hitPoints(10),
	  energyPoints(10),
	  attackDamage(10)
{
	std::cout << "Default constructor called " << this->name << std::endl;
}

// constructor with parameter
ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(10)
{
	std::cout << "Constructor called, name: " << this->name << std::endl;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap &clapTrap)
	: name (clapTrap.name),
	  hitPoints(clapTrap.hitPoints),
	  energyPoints(clapTrap.energyPoints),
	  attackDamage(clapTrap.attackDamage)
{
	std::cout << "Copy constructor called, name: " << this->name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called, name: " << this->name << std::endl;
}

// copy assignment operator
ClapTrap	&ClapTrap::operator=(const ClapTrap &clapTrap)
{
	if (this == &clapTrap) // self-assignment check
		return (*this);

	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;

	std::cout << "Copy assignment operator called, new name: " << this->name << std::endl;

	return (*this);
}
