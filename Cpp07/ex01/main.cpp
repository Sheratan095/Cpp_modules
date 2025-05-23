/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:54:24 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/07 12:06:07 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>

template<typename T>
void	print(T &x)
{
	std::cout << x;
}

int	main()
{
	// The length of an array declared with fixed size MUST be const and known at compile time
	const int intlen = 5, charlen = 10, doublelen = 5;

	int intarray[intlen] = {0, 1, 2, 3, 4};
	std::cout << "Array of integers" << std::endl;
	iter(intarray, intlen, print<int>);
	std::cout << std::endl << std::endl;

	std::cout << "Array of characters" << std::endl;
	char chararray[charlen] = "test12345";
	iter(chararray, charlen - 1, print<char>); // -1 is used to avoid printing the null terminator
	std::cout << std::endl << std::endl;

	double doublearray[doublelen] = {0.1, 1.2, 2.3, 3.4, 4.5};
	std::cout << "Array of doubles" << std::endl;
	iter(doublearray, doublelen, print<double>);

	return (0);
}
