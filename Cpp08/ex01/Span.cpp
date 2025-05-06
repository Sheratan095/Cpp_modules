/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:12:18 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 15:31:46 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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
		throw SpanFullException();
	
	_numbers.insert(_numbers.end(), numbers.begin(), numbers.end());
}

unsigned int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw (NotEnoughNumbersException());

	std::vector<int>	tmpCopy(_numbers);
	std::sort(tmpCopy.begin(), tmpCopy.end());

	// start from the first element (smallest)
	unsigned int	shortest = tmpCopy[0];

	for (size_t i = 0; i < tmpCopy.size(); ++i)
	{
		unsigned int	diff = tmpCopy[i] - tmpCopy[i - 1];
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