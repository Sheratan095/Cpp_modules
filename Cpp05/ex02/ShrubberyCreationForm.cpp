/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:26:12 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 14:32:37 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	if (!this->getIsSigned())
		throw (AForm::FormNotSignedException());

	std::string	fileName = this->target + "_shrubbery";

	std::ofstream	outputFile;
	outputFile.open(fileName.c_str(), std::ios::out | std::ios::trunc);
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not open file " << fileName << std::endl;
		return ;
	}

	outputFile << "                                                         .\n"
		 << "                                              .         ;  \n"
		 << "                 .              .              ;%     ;;   \n"
		 << "                   ,           ,                :;%  %;   \n"
		 << "                    :         ;                   :;%;'     .,   \n"
		 << "           ,.        %;     %;            ;        %;'    ,;\n"
		 << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
		 << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
		 << "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
		 << "                `%;.     ;%;     %;'         `;%%;.%;'\n"
		 << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
		 << "                    `:%;.  :;bd%;          %;@%;'\n"
		 << "                      `@%:.  :;%.         ;@@%;'   \n"
		 << "                        `@%.  `;@%.      ;@@%;         \n"
		 << "                          `@%%. `@%%    ;@@%;        \n"
		 << "                            ;@%. :@%%  %@@%;       \n"
		 << "                              %@bd%%%bd%%:;     \n"
		 << "                                #@%%%%%:;;\n"
		 << "                                %@@%%%::;\n"
		 << "                                %@@@%(o);  . '         \n"
		 << "                                %@@@o%;:(.,'         \n"
		 << "                            `.. %@@@o%::;         \n"
		 << "                               `)@@@o%::;         \n"
		 << "                                %@@(o)::;        \n"
		 << "                               .%@@@@%::;         \n"
		 << "                               ;%@@@@%::;.          \n"
		 << "                              ;%@@@@%%:;;;. \n"
		 << "                          ...;%@@@@@%%:;;;;,.. \n"
		 << "    oxoxoo    ooxoo\n"
		 << "  ooxoxo oo  oxoxooo\n"
		 << " oooo xxoxoo ooo ooox\n"
		 << " oxo o oxoxo  xoxxoxo\n"
		 << "  oxo xooxoooo o ooo\n"
		 << "    ooo\\oo\\  /o/o\n"
		 << "        \\  \\/ /\n"
		 << "         |   /\n"
		 << "         |  |\n"
		 << "         | D|\n"
		 << "         |  |\n"
		 << "         |  |\n"
		 << "  ______/____\\____";
	outputFile.close();
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
