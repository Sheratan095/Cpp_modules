#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		static const int maxMaterias = 4;
		AMateria	*learnedMaterias[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource &materiaSource);
		~MateriaSource();

		MateriaSource	&operator=(const MateriaSource &rhs);

		void		learnMateria(AMateria *materiaToLearn);	
		AMateria*	createMateria(std::string const &type);
};

#endif
