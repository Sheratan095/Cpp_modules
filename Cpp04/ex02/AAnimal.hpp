#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string	type;
		Brain*		brain;

	public:
		AAnimal();
		AAnimal(const AAnimal &animal);
		virtual ~AAnimal();

		AAnimal			&operator=(const AAnimal &rhs);

		std::string		getType() const;
		Brain*			getBrain() const;

		virtual void	makeSound() const = 0;
};

#endif
