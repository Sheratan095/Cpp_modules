/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:55:42 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/04 12:13:57 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
	// try
	// {
		Bureaucrat bob("Bob", 200);
		std::cout << bob << std::endl;
	// }
	// catch(const std::exception &e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	try
	{
		Bureaucrat alice("Alice", 1);
		std::cout << alice << std::endl;

		alice.incrementGrade();
		std::cout << alice << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
