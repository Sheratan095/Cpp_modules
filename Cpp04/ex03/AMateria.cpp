/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:24:02 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:42 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

AMateria::AMateria(const std::string &type) : type(type)
{
	std::cout << "[AMATERIA] constructor called type = " << this->type << std::endl;
}

AMateria::AMateria(AMateria const & aMateria)
{
	std::cout << "[AMATERIA] copy constructor called type = " << this->type << std::endl;

	*this = aMateria;
}

AMateria::~AMateria()
{
	std::cout << "[AMATERIA] destructor called type = " << this->type << std::endl;
}

//--------------------OPERATORS--------------------


AMateria	&AMateria::operator=(AMateria const &rhs)
{
	std::cout << "[AMATERIA] assignment operator called type = " << this->type << std::endl;

	if (&rhs == this)
		return (*this);

	this->type = rhs.getType();

	return (*this);
}

//--------------------GETTERS-SETTERS--------------------


std::string const	&AMateria::getType() const
{
	return (this->type);
}

//--------------------METHODS--------------------


void	AMateria::use(ICharacter &target)
{
	std::cout << "[AMATERIA] type= " << this->type << " is used by: " << target.getName() << std::endl;
}
