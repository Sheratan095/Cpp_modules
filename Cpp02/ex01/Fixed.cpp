/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:29:22 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/07 13:24:44 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : raw_bits(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;

	this->raw_bits = number << bits; // Multiply by 2^bits (shift left by 8 bits)
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;

	this->raw_bits = roundf(number * (1 << bits));
}

Fixed::Fixed(const Fixed &value)
{
	std::cout << "Copy constructor called" << std::endl;

	this->raw_bits = value.raw_bits;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &value)
{
	if (&value == this)
		return (*this);

	std::cout << "Copy assignment operator called" << std::endl;

	this->raw_bits = value.raw_bits;

	return (*this);
}

float Fixed::toFloat( void ) const
{
	return ((float)raw_bits / (1 << bits));
}

int Fixed::toInt( void ) const
{
	return (raw_bits >> bits);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->raw_bits);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;

	this->raw_bits = raw;
}

std::ostream	&operator<<(std::ostream &os, const Fixed &val)
{
	os << val.toFloat();

	return (os);
}
