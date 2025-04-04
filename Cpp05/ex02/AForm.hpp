/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:55:42 by maceccar          #+#    #+#             */
/*   Updated: 2025/04/04 12:13:57 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

// Forward declaration.
class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &src); // Add this line
		virtual	~AForm();

		AForm	&operator=(const AForm &rhs);

		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		virtual void	beSigned(const Bureaucrat &bureaucrat);

		// Pure virtual function. (not implemented in base class).
		//	must be overridden in derived classes.
		// It makes the class abstract.
		virtual void	execute(const Bureaucrat &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char	*what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			const char	*what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif
