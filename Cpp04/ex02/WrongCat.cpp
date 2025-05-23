/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:59:46 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/07 12:06:07 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

WrongCat::WrongCat(): WrongAnimal()
{
	this->type = "WrongCat";

	std::cout << "[WRONGCAT] constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat): WrongAnimal()
{
	*this = wrongCat;

	std::cout << "[WRONGCAT] copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "[WRONGCAT] destructor called" << std::endl;
}


//--------------------OPERATORS--------------------

WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "[WRONGCAT] assignment operator called" << std::endl;

	if (&rhs == this)
		return (*this);

	this->type = rhs.getType();

	return (*this);
}

//--------------------METHODS--------------------


void	WrongCat::makeSound() const
{
	std::cout << "[WRONGCAT] wrong meow meow" << std::endl;
}
