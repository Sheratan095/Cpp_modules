/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:07:15 by maceccar          #+#    #+#             */
/*   Updated: 2025/01/28 16:11:41 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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

	std::cout << "[DiamondTrap] Constructor called, name: " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
	: ClapTrap(diamondTrap),
	  ScavTrap(diamondTrap),
	  FragTrap(diamondTrap)
{
	this->name = diamondTrap.name;
	this->hitPoints = diamondTrap.hitPoints;
	this->energyPoints = diamondTrap.energyPoints;
	this->attackDamage = diamondTrap.attackDamage;
	this->maxHitPoints = diamondTrap.maxHitPoints;

	std::cout << "[DiamondTrap] Copy constructor called, name: " << this->name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] Destructor called, name: " << this->name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	this->name = diamondTrap.name;
	this->hitPoints = diamondTrap.hitPoints;
	this->energyPoints = diamondTrap.energyPoints;
	this->attackDamage = diamondTrap.attackDamage;
	this->maxHitPoints = this->hitPoints;

	std::cout << "[DiamondTrap] Copy assignment operator called, new name: " << this->name << std::endl;

	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I'm " << this->name << " and my ClapTrap name is " << this->ClapTrap::name << std::endl;
}
