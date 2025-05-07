/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:26:12 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/07 12:06:07 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << "[RobotomyRequestForm] default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "[RobotomyRequestForm] constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target)
{
	std::cout << "[RobotomyRequestForm] copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this == &rhs)
		return (*this);

	this->target = rhs.target;

	return (*this);
}

const std::string	&RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

//it's called by bureaucrat.executeForm(form)
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	if (!this->getIsSigned())
		throw (AForm::FormNotSignedException());

	// Generate a random number between 0 and 1
	int ran = random() % 2;

	if (ran == 0)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << this->target << " robotomization failed" << std::endl;

}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &src)
{
	out << "RobotomyRequestForm " << src.getName();
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
