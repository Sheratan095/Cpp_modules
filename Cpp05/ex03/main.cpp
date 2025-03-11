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
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm* form;

	std::cout << "\n||||||INTERN FORM CREATION TESTS||||||\n" << std::endl;

	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form)
	{
		std::cout << *form << std::endl;
		delete (form);
	}

	form = someRandomIntern.makeForm("shrubbery creation", "Garden");
	if (form)
	{
		std::cout << *form << std::endl;
		delete (form);
	}

	form = someRandomIntern.makeForm("presidential pardon", "Alice");
	if (form)
	{
		std::cout << *form << std::endl;
		delete (form);
	}

	form = someRandomIntern.makeForm("unknown form", "Target");
	if (form)
	{
		std::cout << *form << std::endl;
		delete (form);
	}

	return (0);
}