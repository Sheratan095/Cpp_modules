/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:38:34 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:42 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		static const int maxMaterias = 4;
		AMateria	*learnedMaterias[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource &materiaSource);
		~MateriaSource();

		MateriaSource	&operator=(const MateriaSource &rhs);

		void		learnMateria(AMateria *materiaToLearn);	
		AMateria*	createMateria(std::string const &type);
};

#endif
