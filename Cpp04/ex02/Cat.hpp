#ifndef CAT_HPP
#define CAT_HPP

# include "AAnimal.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat &cat);
		~Cat();

		Cat		&operator=(const Cat &rhs);

		void	makeSound() const;
};

#endif
