/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:34:05 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 16:24:51 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat bob("Bob", 140);
	Bureaucrat alice("Alice", 150);

	ShrubberyCreationForm form1("Home");
	ShrubberyCreationForm form2("Garden");

	std::cout << "\n||||||SHRUBBERY CREATION FORM TESTS||||||\n" << std::endl;

	try {
		std::cout << "Trying to execute form1 without signing:" << std::endl;
		form1.execute(bob);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "Signing form1 with Bob:" << std::endl;
		form1.beSigned(bob);
		std::cout << "Executing form1 with Bob:" << std::endl;
		form1.execute(bob);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to execute form2 with Alice (insufficient grade):" << std::endl;
		form2.beSigned(alice);
		form2.execute(alice);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "Signing form2 with Bob and executing:" << std::endl;
		form2.beSigned(bob);
		form2.execute(bob);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
