
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		int			hitPoints;//health
		int			energyPoints;
		int			attackDamage;

	public:
		ClapTrap(); //default constructor
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clapTrap); //copy constructor
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &clapTrap); //copy assignment operator
};

#endif
