
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string		name;
		int				energyPoints;
		unsigned int	hitPoints;//health
		unsigned int	attackDamage;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clapTrap); //copy constructor
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &clapTrap); //copy assignment operator

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif
