/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:29:28 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 15:55:41 by maceccar         ###   ########.fr       */
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
		Fixed();
		Fixed(const Fixed	&value);
		Fixed(const int		number);
		Fixed(const float	number);
		~Fixed();

		Fixed	&operator=(Fixed const &value);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &value);

#endif
