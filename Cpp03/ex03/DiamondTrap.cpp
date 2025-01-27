#include "DiamondTrap.hpp"

// Constructor
DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"),
	  ScavTrap(name),
	  FragTrap(name)
{
	this->name = name;	
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	this->maxHitPoints = this->hitPoints;

	std::cout << "[DiamondTrap	] Constructor called, name: " << this->name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] Destructor called, name: " << this->name << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & diamondTrap)
{
	std::cout << "Assignation operator for \033[97mDiamondTrap\033[0m called" << std::endl;
	this->name = diamondTrap.name;
	this->hitPoints = diamondTrap.hitPoints;
	this->energyPoints = diamondTrap.energyPoints;
	this->attackDamage = diamondTrap.attackDamage;
	this->maxHitPoints = this->hitPoints;
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I'm " << this->name << " and my ClapTrap name is " << this->ClapTrap::name << std::endl;
}
