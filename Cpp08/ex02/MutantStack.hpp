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

		// Iterator typedefs - these expose the underlying container's iterators
		// std::stack has a protected member 'c' which is the container adapter
		typedef typename std::stack<T>::container_type::iterator iterator;               // Regular forward iterator
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;   // Const forward iterator
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator; // Regular reverse iterator
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator; // Const reverse iterator

		// Regular iterator methods - for mutable access to elements
		iterator begin() { return this->c.begin(); }  // Returns iterator to first element
		iterator end() { return this->c.end(); }      // Returns iterator to past-the-end element
		
		// Const iterator methods - for const access to elements
		const_iterator begin() const { return this->c.begin(); }  // Returns const_iterator to first element
		const_iterator end() const { return this->c.end(); }      // Returns const_iterator to past-the-end element
		
		// Reverse iterator methods - for iterating in reverse order
		reverse_iterator rbegin() { return this->c.rbegin(); }    // Returns reverse_iterator to last element
		reverse_iterator rend() { return this->c.rend(); }        // Returns reverse_iterator to before-the-first element
		
		// Const reverse iterator methods - for const reverse iteration
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }  // Returns const_reverse_iterator to last element
		const_reverse_iterator rend() const { return this->c.rend(); }      // Returns const_reverse_iterator to before-the-first element
};

#endif