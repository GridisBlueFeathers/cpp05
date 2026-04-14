#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
#if DEBUG
	std::cerr << "Intern was constructed (default)" << std::endl;
#endif
}

Intern::Intern(const Intern &other) {
	(void)other;
#if DEBUG
	std::cerr << "Intern was constructed (copy)" << std::endl;
#endif
}

Intern::~Intern() {
#if DEBUG
	std::cerr << "Intern was destroyed" << std::endl;
#endif
}

Intern	&Intern::operator=(const Intern &other) {
	(void)other;
	return (*this);
}

const char	*Intern::FormNotFoundException::what() const throw() {
	return ("Form not found");
}

static int	mapArr(const char *arr[], std::string target) {
	for (int i = 0; arr[i]; i++) {
		if (arr[i] == target)
			return (i);
	}
	return (-1);
}

AForm	*Intern::makeForm(std::string name, std::string target) const {
	const char	*arr[] = {"robotomy request", "shrubbery creation", "presidential pardon", NULL};

	switch (mapArr(arr, name)) {
		case (0):
			return (new RobotomyRequestForm(target));
		case (1):
			return (new ShrubberyCreationForm(target));
		case (2):
			return (new PresidentialPardonForm(target));
		default:
			throw FormNotFoundException();
	}
}
