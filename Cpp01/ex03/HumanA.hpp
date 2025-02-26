/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:47:37 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:41 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

// (&weapon) A reference is always bound to an existing object when it is created
//	and it cannot be reassigned to point to another object.
//	It behaves like the object it refers to. 
//	Weapon& weapon guarantees that HumanA always has a valid Weapon object
//		to work with and that weapon will always refer to a valid Weapon

class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void	attack( void );
};

#endif
