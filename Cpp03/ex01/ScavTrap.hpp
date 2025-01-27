
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string		name;
		int				energyPoints;
		unsigned int	hitPoints;//health
		unsigned int	attackDamage;

	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scavTrap); //copy constructor
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &scavTrap); //copy assignment operator

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif
