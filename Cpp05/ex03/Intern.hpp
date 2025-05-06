/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:15:43 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/06 14:32:37 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &intern);
		~Intern();

		Intern	&operator=(const Intern &rhs);

		AForm	*makeForm(std::string formName, std::string target);
		AForm*	createShrubberyCreationForm(const std::string &target);
		AForm*	createRobotomyRequestForm(const std::string &target);
		AForm*	createPresidentialPardonForm(const std::string &target);

		class FormNotFoundException : public std::exception
		{
			const char	*what() const throw();
			};
};

#endif
