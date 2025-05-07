/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:34:05 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/07 12:06:07 by maceccar         ###   ########.fr       */
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
	AForm* rrf;

	std::cout << "\n||||||INTERN FORM CREATION TESTS||||||\n" << std::endl;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete (rrf);
	}

	rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete (rrf);
	}

	rrf = someRandomIntern.makeForm("presidential pardon", "Alice");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete (rrf);
	}

	rrf = someRandomIntern.makeForm("unknown rrf", "Target");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete (rrf);
	}

	return (0);
}
