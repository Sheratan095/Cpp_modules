/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:34:44 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 14:32:37 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		unsigned int	size(void) const;

		class IndexOutOfBoundsException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

//Templates are not compiled into standalone code
#include "Array.tpp"

#endif
