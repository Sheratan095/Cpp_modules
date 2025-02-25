#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(Form &form);
		~Form();

		Form	&operator=(const Form &rhs);

		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void	beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char	*what() const throw();
		};
};

#endif