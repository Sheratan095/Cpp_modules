/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:22:24 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:42 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		static const int equippableMaterias = 4;
		static const int unequippableMaterias = 100;

		std::string	name;

		AMateria*	inventory[equippableMaterias];
		int			inventoryIndex;
		AMateria*	unequipped[unequippableMaterias];
		int			unequippedIndex;

	public:
		Character(std::string const &name);
		Character(Character const &character);
		~Character();

		Character	&operator=(Character const &rhs);

		std::string const	&getName() const;

		void	equip(AMateria* materia);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);
};

#endif
