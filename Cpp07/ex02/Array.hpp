#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array
{
	private:
		T*				_content;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& src);
		~Array(void);

		Array&	operator=(const Array& rhs);
		T&		operator[](unsigned int index) const;

		size_t	size(void) const;

		class IndexOutOfBoundsException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#include "Array.tpp"

#endif
