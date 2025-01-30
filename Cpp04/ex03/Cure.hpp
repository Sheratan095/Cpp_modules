#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &cure);
		~Cure();

		Cure	&operator=(const Cure &rhs);

		Cure	*clone() const;
		void	use(ICharacter &target);
};

#endif
