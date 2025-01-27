#include "ScavTrap.hpp"

//---------------CONSTRUCTORS - DESTRUCTORS---------------

// constructor with parameter
ScavTrap::ScavTrap(std::string name): ClapTrap(name), guardGateStatus(false)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->maxHitPoints = this->hitPoints;

	std::cout << "[ScavTrap] Constructor called, name: " << this->name << std::endl;
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap &slapTrap) : ClapTrap (slapTrap)
{
	std::cout << "[ScavTrap] Copy constructor called, name: " << this->name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] Destructor called, name: " << this->name << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	// check if it's dead
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name <<
			" tried to attack but he's dead" << std::endl;
		return ;
	}

	// check if it has energy point
	if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->name <<
			" tried to attack but he hasn't more energy point" << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << this->name <<
		" attacks " << target <<
		" causing " << this->attackDamage << " points of damage"
		<< std::endl;

	this->energyPoints--;
}

void	ScavTrap::guardGate()
{
	this->guardGateStatus = !this->guardGateStatus;
	if (this->guardGateStatus)
		std::cout << "ScavTrap " << this->name << "'s guard gate is now on" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << "'s guard gate is now off" << std::endl;
} 
