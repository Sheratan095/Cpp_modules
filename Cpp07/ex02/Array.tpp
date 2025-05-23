/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:34:44 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 14:32:37 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

//Reason for .tpp: Templates are not compiled into standalone code.
// The compiler needs the full implementation in the same translation unit where the template is used
// => are to be included and not compiled into file objects

template <typename T>
Array<T>::Array(void) : _content(NULL), _size(0)
{}

// It init the content to 0 (beacause they're pointers)
template <typename T>
Array<T>::Array(unsigned int n) : _content(new T[n]), _size(n)
{}

// Don't need to delete the content, because this is a constructor!!!
template <typename T>
Array<T>::Array(const Array& src): _size(src._size)
{
	_content = new T[src._size];

	for (unsigned int i = 0; i < _size; i++)
		_content[i] = src._content[i];
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] (_content);
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& rhs)
{
	if (this == &rhs)
		return (*this);

	_size = rhs._size;

	delete[] (_content);
	_content = new T[_size];

	for (unsigned int i = 0; i < _size; i++)
		_content[i] = rhs._content[i];

	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw (IndexOutOfBoundsException());

	return (_content[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}

template<typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return ("Index out of bounds");
}
