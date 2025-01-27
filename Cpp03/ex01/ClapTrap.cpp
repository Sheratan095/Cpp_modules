
#include "ClapTrap.hpp"

//---------------CONSTRUCTORS - DESTRUCTORS---------------

// constructor with parameter
ClapTrap::ClapTrap(std::string name): name(name), energyPoints(10), hitPoints(10), attackDamage(10)
{
	this->maxHitPoints = hitPoints;
	std::cout << "[ClapTrap] Constructor called, name: " << this->name << std::endl;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap &clapTrap)
	: name (clapTrap.name),
	  energyPoints(clapTrap.energyPoints),
	  hitPoints(clapTrap.hitPoints),
	  maxHitPoints(clapTrap.maxHitPoints),
	  attackDamage(clapTrap.attackDamage)
{
	std::cout << "[ClapTrap] Copy constructor called, name: " << this->name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] Destructor called, name: " << this->name << std::endl;
}


//---------------ASSIGNMENT OPERATORS---------------

// copy assignment operator
ClapTrap	&ClapTrap::operator=(const ClapTrap &clapTrap)
{
	if (this == &clapTrap) // self-assignment check
		return (*this);

	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;

	std::cout << "[ClapTrap] Copy assignment operator called, new name: " << this->name << std::endl;

	return (*this);
}


//--------------------------------------------------

void	ClapTrap::attack(const std::string& target)
{
	// check if it's dead
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name <<
			" tried to attack but he's dead" << std::endl;
		return ;
	}

	// check if it has energy point
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name <<
			" tried to attack but he hasn't more energy point" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name <<
		" attacks " << target <<
		" causing " << this->attackDamage << " points of damage"
		<< std::endl;

	this->energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return;
	}

	std::cout << "ClapTrap " << this->name << " took " << amount << " damage." << std::endl;
	
	this->hitPoints = (amount >= this->hitPoints) ? 0 : this->hitPoints - amount;

	if (this->hitPoints == 0)
		std::cout << "ClapTrap " << this->name << " is dead " << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " remains with " << this->hitPoints << " hitPoints" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	// check if it has energy point
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name <<
			" tried to attack but he hasn't more energy point" << std::endl;
		return ;
	}

	// check if amount is > 0
	if (amount == 0)
		return ;

	if (this->hitPoints == 0)
		std::cout << "ClapTrap " << this->name << " is resurrected" << std::endl;

	// check if life points have reached their maximum (10)
	this->hitPoints = (this->hitPoints + amount >= this->maxHitPoints) ? this->maxHitPoints : this->hitPoints + amount;

	this->energyPoints--;

	std::cout << "ClapTrap " << this->name << " has been repaired, now he has " 
		<< this->hitPoints << " hitPoints" << std::endl;
}
