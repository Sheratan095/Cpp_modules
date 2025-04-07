/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:59:46 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/07 13:24:44 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

Animal::Animal(): type("Unknown animal")
{
	std::cout << "[ANIMAL] constructor called" << std::endl;

	this->brain = new Brain();
}

Animal::Animal(const Animal &animal)
{
	std::cout << "[ANIMAL] copy constructor called" << std::endl;

	*this = animal;
}

Animal::~Animal()
{
	delete (this->brain);

	std::cout << "[ANIMAL] destructor called, animal type: " << this->type << std::endl;
}


//--------------------OPERATORS--------------------

Animal	&Animal::operator=(const Animal &rhs)
{
	std::cout << "[ANIMAL] assignment operator called" << std::endl;

	if (&rhs == this)
		return (*this);

	this->type = rhs.getType();

	delete (this->brain);
	this->brain = new Brain(*rhs.getBrain());

	return (*this);
}


//--------------------GETTERS-SETTERS--------------------

std::string		Animal::getType() const
{
	return (this->type);
}

Brain	*Animal::getBrain() const
{
	return (this->brain);
}


//--------------------METHODS--------------------


void	Animal::makeSound() const
{
	std::cout << "[ANIMAL] unknown animal sound" << std::endl;
}
