#ifndef DOG_HPP
#define DOG_HPP

# include "AAnimal.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(const Dog &dog);
		~Dog();

		Dog		&operator=(const Dog &rhs);

		void	makeSound() const;
};

#endif
