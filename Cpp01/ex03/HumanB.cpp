/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:26:04 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:41 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

// Initialize `weapon` to `nullptr`, meaning unarmed
HumanB::HumanB(std::string name): name(name)
{
	this->weapon = NULL;
}

HumanB::~HumanB()
{}

void HumanB::attack( void )
{
	std::cout << this->name;

	if (weapon)
		std::cout << " attacks with their " << this->weapon->getType();
	else
		std::cout << " is disarmed";

	std::cout << std::endl;
}

//Take reference just because the main want to do it
void	HumanB::setWeapon(Weapon &newWeapon)
{
	this->weapon = &newWeapon;
}
