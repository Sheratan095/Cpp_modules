/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:59:24 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/04 12:13:57 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

Cat::Cat(): AAnimal()
{
	this->type = "Cat";

	std::cout << "[CAT] constructor called" << std::endl;
}

Cat::Cat(const Cat &cat): AAnimal()
{
	*this = cat;

	std::cout << "[CAT] copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "[CAT] destructor called" << std::endl;
}


//--------------------OPERATORS--------------------

Cat	&Cat::operator=(const Cat &rhs)
{
	std::cout << "[CAT] assignment operator called" << std::endl;

	if (&rhs == this)
		return (*this);

	AAnimal::operator=(rhs);

	return (*this);
}

//--------------------METHODS--------------------


void	Cat::makeSound() const
{
	std::cout << "[CAT] meow meow" << std::endl;
}
