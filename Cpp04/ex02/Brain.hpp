#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		static const int	ideasCount = 100;
		std::string			ideas[ideasCount];

	public:
		Brain();
		Brain(const Brain &brain);
		~Brain();

		Brain	&operator=(const Brain &rhs);

		void		setIdea(int index, std::string idea);
		std::string	getIdea(int index) const;
};

#endif