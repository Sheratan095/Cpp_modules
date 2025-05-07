/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:59:32 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/07 12:06:07 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

WrongAnimal::WrongAnimal(): type("Unknown wrong animal")
{
	std::cout << "[WRONGANIMAL] constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	*this = wrongAnimal;

	std::cout << "[WRONGANIMAL] copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WRONGANIMAL] destructor called, wrong animal type: " << this->type << std::endl;
}


//--------------------OPERATORS--------------------

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "[WRONGANIMAL] assignment operator called" << std::endl;

	if (&rhs == this)
		return (*this);

	this->type = rhs.getType();

	return (*this);
}


//--------------------GETTERS-SETTERS--------------------

std::string		WrongAnimal::getType() const
{
	return (this->type);
}


//--------------------METHODS--------------------


void	WrongAnimal::makeSound() const
{
	std::cout << "[WRONGANIMAL] unknown wrong animal sound" << std::endl;
}
