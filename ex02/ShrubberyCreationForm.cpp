# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(
	"Shrubbery creation form",
	"Default target",
	145,
	137
) {
	if (DEBUG)
		std::cerr << "ShrubberyCreationForm " << getName() << " was created(default)\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(
	other.getName(),
	other.getTarget(),
	other.getToSign(),
	other.getToExecute()
) {
	if (DEBUG)
		std::cerr << "ShrubberyCreationForm " << getName() << " was created(copy)\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm(
	"Shrubbery creation form",
	target,
	145,
	137
) {
	if (DEBUG)
		std::cerr << "ShrubberyCreationForm " << getName() << " was created(target)\n";
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > getToExecute())
		throw Bureaucrat::GradeTooLowException();
}
