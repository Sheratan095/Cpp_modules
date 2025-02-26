/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:29:22 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:41 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <cmath>
#include "Fixed.hpp"

//---------------CONSTRUCTORS - DESTRUCTORS---------------

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


//---------------ASSIGNMENT OPERATORS---------------

Fixed	&Fixed::operator=(Fixed const &value)
{
	if (&value == this)
		return (*this);

	std::cout << "Copy assignment operator called" << std::endl;

	this->raw_bits = value.raw_bits;

	return (*this);
}


//---------------GETTERS - SETTERS---------------

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


//---------------ARTHMETIC OPERATORS---------------

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}


//---------------UNARY OPERATORS---------------

Fixed	&Fixed::operator++(void)
{
	this->raw_bits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	this->raw_bits++;
	return (old);
}

Fixed	&Fixed::operator--(void)
{
	this->raw_bits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	this->raw_bits--;
	return (old);
}


//---------------COMPARISON OPERATORS---------------

bool Fixed::operator==(const Fixed &rhs) const
{
	return (raw_bits == rhs.raw_bits);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->raw_bits != rhs.raw_bits);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (raw_bits < rhs.raw_bits);
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->raw_bits > rhs.raw_bits);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->raw_bits <= rhs.raw_bits);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->raw_bits >= rhs.raw_bits);
}


//---------------CONVERSIONS---------------

float	Fixed::toFloat( void ) const
{
	return ((float)raw_bits / (1 << bits));
}

int		Fixed::toInt( void ) const
{
	return (raw_bits >> bits);
}


//---------------------------------------------

std::ostream	&operator<<(std::ostream &os, const Fixed &val)
{
	os << val.toFloat();

	return (os);
}


//---------------STATIC METHODS---------------

Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.toFloat() < b.toFloat() ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a.toFloat() < b.toFloat() ? a : b);
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.toFloat() > b.toFloat() ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a.toFloat() > b.toFloat() ? a : b);
}
