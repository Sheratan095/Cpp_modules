#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

// Inherit from std::stack allows us to use all the functionalities of std::stack
template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(){}
		MutantStack(const MutantStack<T> &src) : std::stack<T>(src) {};
		~MutantStack(){};

		MutantStack &operator=(const MutantStack &rhs)
		{
			if (*this == rhs)
				return (*this);

			// Call the base class assignment operator
			std::stack<T>::operator=(rhs);
			return (*this);
		};
};

#endif