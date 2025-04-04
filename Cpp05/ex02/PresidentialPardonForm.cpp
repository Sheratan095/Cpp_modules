/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:05:29 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/04 12:13:57 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 72, 45), target("default")
{
	std::cout << "[PresidentialPardonForm] default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 72, 45), target(target)
{
	std::cout << "[PresidentialPardonForm] constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target)
{
	std::cout << "[PresidentialPardonForm] copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this == &rhs)
		return (*this);

	this->target = rhs.target;

	return (*this);
}

const std::string	&PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

//it's called by bureaucrat.executeForm(form)
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();

	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox.\n";
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &src)
{
	out << "PresidentialPardonForm " << src.getName();
	out << "target :" << src.getTarget();
	out << " grade to sign :" << src.getGradeToSign();
	out << " grade to execute :" << src.getGradeToExecute();
	out << " is ";
	if (src.getIsSigned())
		out << "signed" << std::endl;
	else
		out << "not signed" << std::endl;

	return (out);
}
