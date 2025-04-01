/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:10:15 by maceccar          #+#    #+#             */
/*   Updated: 2025/03/27 12:10:15 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

/*
	2147483647 isn't displayed as:
	char: Non displayable
	int: 2147483647
	float: 2.14748e+09f
	double: 2.14748e+09

	becuase decimal notation is required (fidex)
*/

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);

	return (0);
}
