/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:26:12 by maceccar          #+#    #+#             */
/*   Updated: 2025/03/10 15:26:12 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute): name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "[FORM] constructor called" << std::endl;

	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw GradeTooHighException();
	if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw GradeTooLowException();

	this->isSigned = false;
}

//TO DO test if isSigned is set to false
Form::Form(Form &form): name(form.getName()), gradeToSign(form.getGradeToSign()), gradeToExecute(form.getGradeToExecute())
{
	std::cout << "[FORM] copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "[FORM] destructor called" << std::endl;
}

// Modify just the isSigned attribute because all the other attributes are const.
Form	&Form::operator=(const Form &rhs)
{
	std::cout << "[FORM] assignation operator called" << std::endl;

	if (this == &rhs)
		return (*this);

	this->isSigned = rhs.getIsSigned();

	return (*this);
}

const std::string	&Form::getName() const
{
	return (this->name);
}

bool	Form::getIsSigned() const
{
	return (this->isSigned);
}

int	Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->isSigned)
		return ;

	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();

	this->isSigned = true;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName();
	out << " level :" << form.getGradeToSign() << " ";
	out << " grade to execute :" << form.getGradeToExecute();
	out << " is ";
	if (form.getIsSigned())
		out << "signed" << std::endl;
	else
		out << "not signed" << std::endl;
	return out;
}
