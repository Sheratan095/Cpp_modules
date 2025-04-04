/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:13:41 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/04 12:13:57 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <ostream>

static void	testArithmeticOperators();
static void	testUnaryOperators();
static void	testComparisonOperators();
static void	testMinMax();

int main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	testArithmeticOperators();
	testUnaryOperators();
	testComparisonOperators();
	testMinMax();

	return (0);
}

static void	testArithmeticOperators()
{
	std::cout << std::endl << "TESTING ARITHMETIC OPERATORS:" << std::endl;

	Fixed a(2);
	Fixed b(5);
	
	Fixed result;

	// Test addition
	result = a + b;
	std::cout << "a + b = " << result << std::endl;

	// Test subtraction
	result = a - b;
	std::cout << "a - b = " << result << std::endl;

	// Test multiplication
	result = a * b;
	std::cout << "a * b = " << result << std::endl;

	// Test division
	result = a / b;
	std::cout << "a / b = " << result << std::endl;

	std::cout << std::endl;
}

static void	testUnaryOperators()
{
	std::cout << std::endl << "TESTING UNARY OPERATORS:" << std::endl;

	Fixed a(5);
	Fixed result;

	// Test pre-increment
	result = ++a;
	std::cout << "Pre-increment: " << result << std::endl;

	// Test post-increment
	result = a++;
	std::cout << "Post-increment: " << result << std::endl;
	std::cout << "After post-increment: " << a << std::endl;

	// Test pre-decrement
	result = --a;
	std::cout << "Pre-decrement: " << result << std::endl;

	// Test post-decrement
	result = a--;
	std::cout << "Post-decrement: " << result << std::endl;
	std::cout << "After post-decrement: " << a << std::endl;

	std::cout << std::endl;
}

static void	testComparisonOperators()
{
	std::cout << std::endl << "TESTING COMPARISON OPERATORS:" << std::endl;

	Fixed a(5);
	Fixed b(5);
	Fixed c(10);

	// Test equality
	std::cout << "a == b: " << (a == b ? "true" : "false") << std::endl;
	std::cout << "a == c: " << (a == c ? "true" : "false") << std::endl;

	// Test inequality
	std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl;
	std::cout << "a != c: " << (a != c ? "true" : "false") << std::endl;

	// Test less than
	std::cout << "a < c: " << (a < c ? "true" : "false") << std::endl;

	// Test greater than
	std::cout << "a > c: " << (a > c ? "true" : "false") << std::endl;

	// Test less than or equal to
	std::cout << "a <= b: " << (a <= b ? "true" : "false") << std::endl;

	// Test greater than or equal to
	std::cout << "a >= c: " << (a >= c ? "true" : "false") << std::endl;

	std::cout << std::endl;
}

static void	testMinMax()
{
	std::cout << std::endl << "TESTING MIN AND MAX FUNCTIONS:" << std::endl;

	Fixed a(5);
	Fixed b(10);
	
	std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;
	std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;

	std::cout << std::endl;
}
