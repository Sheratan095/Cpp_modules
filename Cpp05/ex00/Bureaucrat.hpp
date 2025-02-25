#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat &bureaucrat);
		~Bureaucrat();

		Bureaucrat	&operator=(const Bureaucrat &rhs);

		const std::string	&getName() const;
		int					getGrade() const;

		void incrementGrade();
		void decrementGrade();

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