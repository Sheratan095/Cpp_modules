/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:22:54 by maceccar          #+#    #+#             */
/*   Updated: 2025/02/26 16:22:54 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("default form"), gradeToSign(MIN_GRADE), gradeToExecute(MIN_GRADE)
{
	std::cout << "[FORM] default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "[FORM] constructor called" << std::endl;

	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw GradeTooHighException();
	if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw GradeTooLowException();

	this->isSigned = false;
}

AForm::AForm(AForm &form): name(form.getName()), gradeToSign(form.getGradeToSign()), gradeToExecute(form.getGradeToExecute())
{
	this->isSigned = false;

	std::cout << "[FORM] copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "[FORM] destructor called" << std::endl;
}

// Modify just the isSigned attribute because all the other attributes are const.
AForm	&AForm::operator=(const AForm &rhs)
{
	std::cout << "[FORM] copy assignment operator called" << std::endl;

	if (this == &rhs)
		return (*this);

	this->isSigned = rhs.getIsSigned();

	return (*this);
}

const std::string	&AForm::getName() const
{
	return (this->name);
}

bool	AForm::getIsSigned() const
{
	return (this->isSigned);
}

int	AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->isSigned)
		return ;

	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();

	this->isSigned = true;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out << "Form " << form.getName();
	out << " grade to sign :" << form.getGradeToSign();
	out << " grade to execute :" << form.getGradeToExecute();
	out << " is ";
	if (form.getIsSigned())
		out << "signed" << std::endl;
	else
		out << "not signed" << std::endl;

	return (out);
}
