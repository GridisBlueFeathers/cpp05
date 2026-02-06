/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:17:38 by svereten          #+#    #+#             */
/*   Updated: 2026/02/06 14:45:21 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("John"), _grade(150) {
#if DEBUG
	std::cerr << "Bureaucrat " << _name << " was created(default)\n";
#endif
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):
	_name(other._name),
	_grade(other._grade) {
#if DEBUG
	std::cerr << "Bureaucrat " << _name << " was created(copy)\n";
#endif
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade):
	_name(name),
	_grade(grade) {
	if (_grade == 0)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
#if DEBUG
	std::cerr << "Bureaucrat " << _name << " was created(name, rank)\n";
#endif
}

Bureaucrat::~Bureaucrat() {
#if DEBUG
	std::cerr << "Bureaucrat " << _name << " was destroyed\n";
#endif
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return (*this);
}

const std::string	&Bureaucrat::getName() const {
	return (_name);
}

unsigned int	Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::increaseGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decreaseGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << getName() << " couldn't sign "
			<< form.getName() << " because of "
			<< e.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << ".";
	return (out);
}
