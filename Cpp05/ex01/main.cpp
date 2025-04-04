/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:34:05 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/04 12:13:57 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Form form("Form", 150, 150);

	std::cout << form.getIsSigned() << std::endl;

	form.beSigned(Bureaucrat("Jack", 75));

	std::cout << form.getIsSigned() << std::endl;

	// in this case the copy constructor is called and not the copy assignment operator
	// because the object is not already created.
	Form prova = form;
	std::cout << prova.getIsSigned() << std::endl;

	// in this the copy assignment operator is called because the object is already created.
	Form prova2("prova", 100, 100);
	prova2 = form;
	std::cout << prova2.getIsSigned() << std::endl;
	
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

	std::cout << std::endl << std::endl;

	Form formA("FormA", 100, 100);
	Form formB("FormB", 50, 50);

	std::cout << "Before assignment:" << std::endl;
	std::cout << "FormA is signed: " << formA.getIsSigned() << std::endl;
	std::cout << "FormB is signed: " << formB.getIsSigned() << std::endl;

	formA.beSigned(bureaucrat_1);
	formB = formA;

	std::cout << "After assignment:" << std::endl;
	std::cout << "FormA is signed: " << formA.getIsSigned() << std::endl;
	std::cout << "FormB is signed: " << formB.getIsSigned() << std::endl;
}
