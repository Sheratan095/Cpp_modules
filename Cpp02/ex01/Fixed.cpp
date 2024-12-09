/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:29:22 by maceccar          #+#    #+#             */
/*   Updated: 2024/12/09 16:31:54 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : raw_bits(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &value)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = value;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;

	//Left-shifting a number by 8 bits is equivalent to multiplying it by 2^8=256
	this->raw_bits = number << bits;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Fixed const &value)
{
	return (os << value.toFloat());
}

Fixed	&Fixed::operator=(Fixed const &value)
{
	std::cout << "Copy assignment operator called" << std::endl;

	this->raw_bits = value.getRawBits();

	return (*this);
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
