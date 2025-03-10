#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(PresidentialPardonForm const & rhs);

		const	std::string &getTarget() const;

		void	execute(Bureaucrat const & executor) const;
};

#endif