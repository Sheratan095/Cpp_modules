#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	std::cout << "[BUREAUCRAT] constructor called" << std::endl;

	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	if (grade > MIN_GRADE)
		throw GradeTooLowException();

	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &bureaucrat) : name(bureaucrat.getName()), grade(bureaucrat.getGrade())
{
	std::cout << "[BUREAUCRAT] copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[BUREAUCRAT] destructor called" << std::endl;
}

// Not changing tha name because it is a const.
// the check is done on &rhs because it is a reference to the object.
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "[BUREAUCRAT] assignation operator called" << std::endl;

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
void Bureaucrat::incrementGrade()
{
	if (this->grade == MAX_GRADE)
		throw GradeTooHighException();

	this->grade--;
}

// Check if the min grade is reached.
void Bureaucrat::decrementGrade()
{
	if (this->grade == MIN_GRADE)
		throw GradeTooLowException();

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
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();

	return (out);
}