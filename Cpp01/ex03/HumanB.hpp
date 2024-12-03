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