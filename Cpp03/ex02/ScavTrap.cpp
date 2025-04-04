/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:50:23 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/04 12:13:57 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap (scavTrap)
{
	this->guardGateStatus = scavTrap.guardGateStatus;

	std::cout << "[ScavTrap] Copy constructor called, name: " << this->name << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &scavTrap)
{
	if (this == &scavTrap)
		return (*this);

	this->name = scavTrap.name;
	this->hitPoints = scavTrap.hitPoints;
	this->energyPoints = scavTrap.energyPoints;
	this->attackDamage = scavTrap.attackDamage;
	this->maxHitPoints = scavTrap.maxHitPoints;
	this->guardGateStatus = scavTrap.guardGateStatus;

	std::cout << "[ScavTrap] Copy assignment operator called, new name: " << this->name << std::endl;

	return (*this);
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
