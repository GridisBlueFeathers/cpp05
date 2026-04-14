#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();

		void	execute(Bureaucrat const &executor) const;
};

#endif
