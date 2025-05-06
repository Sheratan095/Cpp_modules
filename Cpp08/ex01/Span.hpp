/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:31:45 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 15:31:46 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iterator>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span(unsigned int n);
		Span(const Span &other);
		~Span();

		Span	&operator=(const Span &rhs);

		void			addNumber(const int& n);
		void			addNumbers(const std::vector<int>& numbers);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		class	SpanFullException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class	NotEnoughNumbersException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
