#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string	type;
		Brain*		brain;

	public:
		Animal();
		Animal(const Animal &animal);
		virtual ~Animal();

		Animal			&operator=(const Animal &rhs);

		std::string		getType() const;
		Brain*			getBrain() const;

		virtual void	makeSound() const;
};

#endif
