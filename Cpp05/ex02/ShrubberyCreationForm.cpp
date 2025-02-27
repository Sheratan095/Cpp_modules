#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << "[SHRUBBERYCREATIONFORM] default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "[SHRUBBERYCREATIONFORM] constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
{
	std::cout << "[SHRUBBERYCREATIONFORM] copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[SHRUBBERYCREATIONFORM] destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this == &rhs)
		return (*this);

	this->target = rhs.target;

	return (*this);
}

const std::string	&ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

//it's called by bureaucrat.executeForm(form)
void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &src)
{
	out << "ShrubberyCreationForm " << src.getName();
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