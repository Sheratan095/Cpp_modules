/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:22:54 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 14:32:37 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default bureaucrat"), grade(MIN_GRADE)
{
	std::cout << "[BUREAUCRAT] default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	std::cout << "[BUREAUCRAT] constructor called" << std::endl;

	if (grade < MAX_GRADE)
		throw (GradeTooHighException());
	if (grade > MIN_GRADE)
		throw (GradeTooLowException());

	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.getName()), grade(bureaucrat.getGrade())
{
	std::cout << "[BUREAUCRAT] copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[BUREAUCRAT] destructor called" << std::endl;
}

// Not changing tha name because it is a const.
// The check is done on &rhs because it is a reference to the object.
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "[BUREAUCRAT] copy assignment operator called" << std::endl;

	if (this == &rhs)
		return (*this);

	this->grade = rhs.getGrade();

	return (*this);
}

const std::string	&Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

// Check it the max grade is reached.
void	Bureaucrat::incrementGrade()
{
	if (this->grade == MAX_GRADE)
		throw (GradeTooHighException());

	this->grade--;
}

// Check if the min grade is reached.
void	Bureaucrat::decrementGrade()
{
	if (this->grade == MIN_GRADE)
		throw (GradeTooLowException());

	this->grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

// this is a pointer to the object itself.
// *this is the object itself (dereferenced).
// std::cout << *this << std::endl.
std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";

	return (out);
}
