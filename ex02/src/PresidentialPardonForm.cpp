#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm(
		"PresidentialPardonForm",
		25,
		5
	) {
#if DEBUG
	std::cerr << "PresidentialPardonForm " << _name << " was created(default)\n";
#endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm(
		other.getName(),
		other.getToSign(),
		other.getToExecute()
	) {
#if DEBUG
	std::cerr << "PresidentialPardonForm " << _name << " was created(copy)\n";
#endif
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm (
		target,
		25,
		5
	) {
#if DEBUG
	std::cerr << "PresidentialPardonForm " << _name << " was created(target)\n";
#endif
}

PresidentialPardonForm::~PresidentialPardonForm() {
#if DEBUG
	std::cerr << "PresidentialPardonForm " << _name << " was destroyed\n";
#endif
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw FormIsNotSignedException();
	if (executor.getGrade() > getToExecute())
		throw GradeTooLowException();

	std::cout << getName() << " was pardoned by Zaphod Beeblebrox" << std::endl;
}
