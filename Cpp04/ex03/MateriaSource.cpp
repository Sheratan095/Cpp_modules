/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:25:26 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:42 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

//--------------------CONSTRUCTORS & DESTRUCTOR--------------------

MateriaSource::MateriaSource()
{
	std::cout << "[MATERIASOURCE] default constructor called" << std::endl;

	for (int i = 0; i < this->maxMaterias; i++)
		this->learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &materiaSource)
{
	std::cout << "[MATERIASOURCE] copy constructor called" << std::endl;

	*this = materiaSource;
}

MateriaSource::~MateriaSource()
{
	std::cout << "[MATERIASOURCE] destructor called" << std::endl;

	for (int i = 0; i < maxMaterias	; i++)
	{
		if (this->learnedMaterias[i])
			delete (learnedMaterias[i]);
	}
}

//--------------------OPERATORS--------------------


MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
	std::cout << "[MATERIASOURCE] assignment operator called" << std::endl;

	if (this == &materiaSource)
		return (*this);

	for (int i = 0; i < this->maxMaterias; i++)
	{
		this->learnedMaterias[i] = NULL;

		if (materiaSource.learnedMaterias[i])
			this->learnedMaterias[i] = materiaSource.learnedMaterias[i]->clone();
	}

	return (*this);
}


//--------------------METHODS--------------------

void MateriaSource::learnMateria(AMateria *materiaToLearn)
{
	if (!materiaToLearn)
	{
		std::cout << "[MATERIASOURCE] can't learn a NULL materia " << std::endl;
		return ;
	}

	for (int i = 0; i < this->maxMaterias; i++)
	{
		//Reach the first avaible poistion
		if(!this->learnedMaterias[i])
		{
			this->learnedMaterias[i] = materiaToLearn;

			std::cout << "[MATERIASOURCE] learned: " << materiaToLearn->getType() << std::endl;
			return ;
		}
	}

	std::cout << "[MATERIASOURCE] not enough space to store a new materia" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->learnedMaterias[i] && this->learnedMaterias[i]->getType() == type)
			return (this->learnedMaterias[i]->clone());
	}

	std::cout << "[MATERIASOURCE] meteria type " << type << " NOT Found." << std::endl;
	return (NULL);
}
