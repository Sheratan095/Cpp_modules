/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:21:22 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/07 12:06:07 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

Character::Character(std::string const &name) : name(name)
{
	std::cout << "[CHARACTER] name: "<< this->name << "constructor called" << std::endl;

	//NULL initialize the inventory
	for (int i = 0; i < this->equippableMaterias; i++)
		this->inventory[i] = NULL;

	//NULL initialize the "drop" inventory
	for (int i = 0; i < this->unequippableMaterias; i++)
		this->unequipped[i] = NULL;

	//Initialize indexes
	this->inventoryIndex = 0;
	this->unequippedIndex = 0;
}

Character::Character(const Character &character)
{
	std::cout << "[CHARACTER] name: "<< this->name << "copy constructor called" << std::endl;

	*this = character;
}

//--------------------OPERATORS--------------------

Character & Character::operator=(Character const &rhs)
{
	std::cout << "[CHARACTER] name: "<< this->name << "assignment operator called" << std::endl;

	if (&rhs == this)
		return (*this);

	this->name = rhs.name;
	this->inventoryIndex = rhs.inventoryIndex;
	this->unequippedIndex = rhs.unequippedIndex;

	//Copy elements of the inventory
	for (int i = 0; i < this->equippableMaterias; i++)
	{
		if (this->inventory[i])
			delete (this->inventory[i]);

		if (rhs.inventory[i])
			this->inventory[i] = rhs.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}

	//Copy elements of "drop" inventory
	for (int i = 0; i < this->unequippableMaterias; i++)
	{
		if (this->unequipped[i])
			this->unequipped[i] = rhs.unequipped[i]->clone();
		else
			this->unequipped[i] = NULL;
	}

	return (*this);
}

Character::~Character()
{
	std::cout << "[CHARACTER] name: "<< this->name << " destructor called" << std::endl;

	for (int i = 0; i < equippableMaterias; i++)
	{
		if (this->inventory[i])
			delete (inventory[i]);
	}

	for (int i = 0; unequipped[i] && i < unequippedIndex; i++)
	{
		if (this->inventory[i])
			delete (unequipped[i]);
	}
}

//--------------------OPERATORS--------------------

std::string	const	&Character::getName() const
{
	return (this->name);
}


//--------------------METHODS--------------------

void	Character::equip(AMateria* materia)
{
	if (inventoryIndex == 3)
		std::cout << "[CHARACTER] name: " << this->name << "'s inventory is full" << std::endl;
	else
	{
		inventory[inventoryIndex] = materia;
		inventoryIndex++;

		std::cout << "[CHARACTER] name: " << this->name << "added to his inventory " << materia->getType() << std::endl;
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->equippableMaterias)
	{
		std::cout << "[CHARACTER] name: "<< this->name << " wrong index" << std::endl;
		return ;
	}

	if (!this->inventory[idx])
	{
		std::cout << "[CHARACTER] name: "<< this->name << " has nothing equipped at " << idx << std::endl;
		return ;
	}

	//Reached the limit of the trash
	if (this->unequippedIndex == this->unequippableMaterias - 1)
	{
		std::cout << "[CHARACTER] name: "<< this->name << " can't unequip animore" << std::endl;
		return ;
	}

	this->unequipped[unequippedIndex] = this->inventory[idx];
	this->inventory[idx] = NULL;

	unequippedIndex--;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "[CHARACTER] name: "<< this->name << " wrong index" << std::endl;
		return ;
	}

	if (!inventory[idx])
	{
		std::cout << "[CHARACTER] name: "<< this->name << " has nothing equipped at " << idx << std::endl;
		return ;
	}

	inventory[idx]->use(target);
}
