/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:46:59 by maceccar          #+#    #+#             */
/*   Updated: 2025/03/10 15:26:12 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

Cure::Cure() : AMateria("cure")
{
	std::cout << "[CURE] constructor called" << std::endl;
}

Cure::Cure(Cure const &cure) : AMateria(cure.getType())
{
	std::cout << "[CURE] copy constructor called" << std::endl;

	*this = cure;
}

Cure::~Cure()
{
	std::cout << "[CURE] destructor called" << std::endl;
}

//--------------------OPERATORS--------------------


Cure	&Cure::operator=(Cure const &rhs)
{
	std::cout << "[CURE] assignment operator called" << std::endl;

	if (&rhs == this)
		return (*this);

	AMateria::operator=(rhs);

	return (*this);
}	

//--------------------METHODS--------------------


void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure	*Cure::clone() const
{
	return (new Cure(*this));
}
