#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <string>

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	Intern	&operator=(const Intern &other);

	AForm	*makeForm(std::string name, std::string target) const;

	class FormNotFoundException: public std::exception {
		public:
			virtual const char	*what() const throw();
	};
};

#endif
