/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:26:09 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:41 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

// *weapon A pointer to Weapon allows for a nullable state.

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;

	public:
		HumanB(std::string name);
		~HumanB();

		void	attack( void );
		void	setWeapon(Weapon &weapon);
};

#endif
