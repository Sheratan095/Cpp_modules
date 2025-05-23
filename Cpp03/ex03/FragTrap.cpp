/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:50:23 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/07 12:06:07 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//---------------CONSTRUCTORS - DESTRUCTORS---------------

// constructor with parameter
FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	this->maxHitPoints = this->hitPoints;

	std::cout << "[FragTrap] Constructor called, name: " << this->name << std::endl;
}

// copy constructor
FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap (fragTrap)
{
	std::cout << "[FragTrap] Copy constructor called, name: " << this->name << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &fragTrap)
{
	if (this == &fragTrap)
		return (*this);

	this->name = fragTrap.name;
	this->hitPoints = fragTrap.hitPoints;
	this->energyPoints = fragTrap.energyPoints;
	this->attackDamage = fragTrap.attackDamage;
	this->attackDamage = fragTrap.maxHitPoints;

	std::cout << "[fragTrap] Copy assignment operator called, new name: " << this->name << std::endl;

	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] Destructor called, name: " << this->name << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	// check if it's dead
	if (this->hitPoints == 0)
	{
		std::cout << "FragTrap " << this->name <<
			" tried to attack but he's dead" << std::endl;
		return ;
	}

	// check if it has energy point
	if (this->energyPoints == 0)
	{
		std::cout << "FragTrap " << this->name <<
			" tried to attack but he hasn't more energy point" << std::endl;
		return ;
	}

	std::cout << "FragTrap " << this->name <<
		" attacks " << target <<
		" causing " << this->attackDamage << " points of damage"
		<< std::endl;

	this->energyPoints--;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " requests a high five! ✋" << std::endl;
}
