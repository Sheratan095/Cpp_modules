/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:34:05 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/05 12:38:15 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout <<  "||||||BUREAUCRAT INSTATIATE TESTS||||||\n"  << std::endl;

	try {
		std::cout <<  "Trying to create a bureaucrat with a grade of 0:"  << std::endl;
		Bureaucrat tooHigh("TooHigh", 0);
	} catch (std::exception &e) {
		std::cerr <<  "Exception: "  << e.what() <<  std::endl;
	}

	try {
		std::cout <<  "Trying to create a bureaucrat with a grade of 151:"  << std::endl;
		Bureaucrat tooLow("TooLow", 151);
	} catch (std::exception &e) {
		std::cerr <<  "Exception: " << e.what() <<  std::endl;
	}

	Bureaucrat bureaucrat_0("aaa", 150);
	Bureaucrat bureaucrat_1("Jack", 75);

	std::cout <<  "\n||||||BUREAUCRAT TESTS||||||\n"  << std::endl;

	try {
		std::cout <<  "-----Before Decrement-----"  << std::endl;
		std::cout << "Bureaucrat name:" << bureaucrat_0.getName() << std::endl;
		std::cout << "Bureaucrat grade:"  << bureaucrat_0.getGrade() << std::endl;

		std::cout <<  "-----After Decrement-----"  << std::endl;
		bureaucrat_0.decrementGrade();
		std::cout << "Bureaucrat name:" << bureaucrat_0.getName() << std::endl;
		std::cout << "Bureaucrat grade:"  << bureaucrat_0.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cerr <<  "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout <<  "-----Before Increment-----"  << std::endl;
		std::cout << "Bureaucrat name:" << bureaucrat_1.getName() << std::endl;
		std::cout << "Bureaucrat grade:"  << bureaucrat_1.getGrade() << std::endl;

		std::cout <<  "-----After Increment-----"  << std::endl;
		bureaucrat_1.incrementGrade();
		std::cout << "Bureaucrat name:" << bureaucrat_1.getName() << std::endl;
		std::cout << "Bureaucrat grade:"  << bureaucrat_1.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cerr <<  "Exception: " << e.what() <<  std::endl;
	}

	std::cout <<  "\n||||||FORM TESTS||||||\n"  << std::endl;

	Form form_0("Form_0", 150, 150);
	Form form_1("Form_1", 80, 80);

	try {
		std::cout <<  "-----Trying to sign-----"  << std::endl;
		std::cout << "Bureaucrat name:" << bureaucrat_0.getName() << std::endl;
		std::cout << "Bureaucrat grade:"  << bureaucrat_0.getGrade() << std::endl;
		bureaucrat_0.signForm(form_0);
		form_0.beSigned(bureaucrat_1);
	} catch (std::exception &e) {
		std::cerr <<   "Exception: " << e.what() << std::endl;
	}
}