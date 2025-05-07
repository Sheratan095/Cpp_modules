/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:29:33 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/07 12:06:07 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	a.setRawBits(8);

	std::cout << std::endl;

	Fixed b( a );
	b.setRawBits(4389);

	std::cout << std::endl;

	Fixed c;

	std::cout << std::endl;

	c = b;

	std::cout << std::endl;

	std::cout << a.getRawBits() << std::endl << std::endl;
	std::cout << b.getRawBits() << std::endl << std::endl;
	std::cout << c.getRawBits() << std::endl << std::endl;

	return (0);
}
