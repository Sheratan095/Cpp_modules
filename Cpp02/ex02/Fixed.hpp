/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:29:28 by maceccar          #+#    #+#             */
/*   Updated: 2025/01/28 16:11:41 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		static const int	bits = 8;

		int					raw_bits;

	public:
		static const	Fixed &min(const Fixed &a, const Fixed &b);	
		static			Fixed &min(Fixed &a, Fixed &b);
		static const	Fixed &max(const Fixed &a, const Fixed &b);
		static			Fixed &max(Fixed &a, Fixed &b);

		Fixed();
		Fixed(const Fixed	&value);
		Fixed(const int		number);
		Fixed(const float	number);
		~Fixed();

		Fixed	&operator=(Fixed const &value);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &value);

#endif
