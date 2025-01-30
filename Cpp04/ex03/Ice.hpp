#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &ice);
		~Ice();

		Ice	&operator=(const Ice &i);

		Ice		*clone() const;
		void	use(ICharacter &target);
};

#endif
