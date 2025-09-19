/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:28:26 by svereten          #+#    #+#             */
/*   Updated: 2025/09/19 14:13:00 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Form.hpp"

Form::Form():
	_name("Some form"),
	_signed(false),
	_toSign(150),
	_toExecute(150) {
	if (DEBUG)
		std::cerr << "Form " << _name << " was created(default)\n";
}

Form::Form(const Form &other):
	_name(other._name),
	_signed(other._signed),
	_toSign(other._toSign),
	_toExecute(other._toExecute) {
	if (DEBUG)
		std::cerr << "Form " << _name << " was created(copy)\n";
}

Form::Form(const std::string &name, unsigned int toSign, unsigned int toExecute):
	_name(name),
	_signed(false),
	_toSign(toSign),
	_toExecute(toExecute) {
	if (_toSign < 1 || _toExecute < 1)
		throw Form::GradeTooHighException();
	if (_toSign > 150 || _toExecute > 150)
		throw Form::GradeTooLowException();
	if (DEBUG)
		std::cerr << "Form " << _name << " was created(name, toSign, toExecute)\n";
}

Form::~Form() {
	if (DEBUG)
		std::cerr << "Form " << _name << " was destroyed\n";
}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

const std::string	&Form::getName() const {
	return (_name);
}

bool	Form::getSigned() const {
	return (_signed);
}

unsigned int	Form::getToSign() const {
	return (_toSign);
}

unsigned int	Form::getToExecute() const {
	return (_toExecute);
}

void	Form::beSigned(Bureaucrat bureaucrat) {
	if (_signed)
		throw Form::IsSignedException();
	if (bureaucrat.getGrade() > _toSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char	*Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char	*Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char	*Form::IsSignedException::what() const throw() {
	return ("Form is already signed");
}

std::ostream	&operator<<(std::ostream &out, Form form) {
	out << "Form: " << form.getName() << "\n"
		<< "Status: " << (form.getSigned() ? "signed" : "not signed") << "\n"
		<< "Grade to sign: " << form.getToSign() << "\n"
		<< "Grade to execute: " << form.getToExecute() << std::endl;
	return (out);
}
