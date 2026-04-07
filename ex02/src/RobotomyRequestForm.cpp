#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():
	AForm(
		"RobotomyRequestForm",
		72,
		45
	)
{
	srand(time(NULL));
#if DEBUG
	std::cerr << "RobotomyRequestForm " << _name << " was created(default)\n";
#endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	AForm(
		other.getName(),
		other.getToSign(),
		other.getToExecute()
	)
{
#if DEBUG
	std::cerr << "RobotomyRequestForm " << _name << " was created(copy)\n";
#endif
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm (
		target,
		72,
		45
	)
{
	srand(time(NULL));
#if DEBUG
	std::cerr << "RobotomyRequestForm " << _name << " was created(target)\n";
#endif
}

RobotomyRequestForm::~RobotomyRequestForm() {
#if DEBUG
	std::cerr << "RobotomyRequestForm " << _name << " was destroyed\n";
#endif
}

const char	*RobotomyRequestForm::RoboromyFailException::what() const throw() {
	return ("There was an error during robotomization");
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw FormIsNotSignedException();
	if (executor.getGrade() > getToExecute())
		throw Bureaucrat::GradeTooLowException();
	if (RAND % 2)
		std::cout << getName() << " was sucessfully robotomized!" << std::endl;
	else
		throw RoboromyFailException();
}
