/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:55:42 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/07 13:24:44 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

#include "AForm.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

// Forward declaration.
class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();

		Bureaucrat	&operator=(const Bureaucrat &rhs);

		const std::string	&getName() const;
		int					getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

		void	signForm(AForm &form) const;
		void	executeForm(AForm const &form);

		// NETEST CLASSES
		class GradeTooHighException : public std::exception
		{
			// throw() is a specifier that tells the compiler that the
			//		function does not throw exceptions .
			// what() is a virtual function inherited from std::exception.
			const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
