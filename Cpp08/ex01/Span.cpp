/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:12:18 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/07 12:06:07 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

Span::Span(unsigned int n) : _maxSize(n), _numbers(0)
{}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{}

Span::~Span()
{}

Span	&Span::operator=(const Span &rhs)
{
	if (this == &rhs)
		return (*this);

	this->_maxSize = rhs._maxSize;
	this->_numbers = rhs._numbers;

	return (*this);
}

void	Span::addNumber(const int& n)
{
	if (this->_numbers.size() >= this->_maxSize)
		throw (SpanFullException());

	this->_numbers.push_back(n);
}

void	Span::addNumbers(const std::vector<int>& numbers)
{
	if (_numbers.size() + numbers.size() > _maxSize)
		throw (SpanFullException());
	
	_numbers.insert(_numbers.end(), numbers.begin(), numbers.end());
}

unsigned int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw (NotEnoughNumbersException());

	std::vector<int>	tmpCopy(_numbers);
	std::sort(tmpCopy.begin(), tmpCopy.end());

	// Initialize with the maximum possible unsigned int value
	unsigned int shortest = tmpCopy[0];

	// Proper loop starting from index 1 and comparing with previous element
	for (size_t i = 1; i < tmpCopy.size(); ++i)
	{
		// Calculate difference between adjacent elements
		unsigned int diff = tmpCopy[i] - tmpCopy[i-1];

		if (diff < shortest)
			shortest = diff;
	}

	return (shortest);
}

unsigned int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw (Span::NotEnoughNumbersException());

	std::vector<int>	tmpCopy(_numbers);
	std::sort(tmpCopy.begin(), tmpCopy.end());

//			last element(biggest)		  - first element(smallest)
	return (tmpCopy[_numbers.size() - 1] - tmpCopy[0]);
}

const char	*Span::SpanFullException::what() const throw()
{
	return ("Span is full");
}

const char	*Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers to find a span");
}
