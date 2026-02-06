/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:28:26 by svereten          #+#    #+#             */
/*   Updated: 2026/02/06 15:28:15 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AForm.hpp"

AForm::AForm():
	_name("Some form"),
	_toSign(150),
	_toExecute(150),
	_signed(false) {
#if DEBUG
	std::cerr << "Form " << _name << " was created(default)\n";
#endif
}

AForm::AForm(const AForm &other):
	_name(other._name),
	_toSign(other._toSign),
	_toExecute(other._toExecute),
	_signed(other._signed) {
#if DEBUG
	std::cerr << "Form " << _name << " was created(copy)\n";
#endif
}

AForm::AForm(const std::string &name,
	unsigned int toSign,
	unsigned int toExecute):
	_name(name),
	_toSign(toSign),
	_toExecute(toExecute), 
	_signed(false) {
	if (_toSign < 1 || _toExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_toSign > 150 || _toExecute > 150)
		throw Bureaucrat::GradeTooLowException();
#if DEBUG
	std::cerr << "Form " << _name << " was created(name, toSign, toExecute)\n";
#endif
}

AForm::~AForm() {
#if DEBUG
	std::cerr << "Form " << _name << " was destroyed\n";
#endif
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

const std::string	&AForm::getName() const {
	return (_name);
}

unsigned int	AForm::getToSign() const {
	return (_toSign);
}

unsigned int	AForm::getToExecute() const {
	return (_toExecute);
}

bool	AForm::getSigned() const {
	return (_signed);
}

void	AForm::beSigned(Bureaucrat bureaucrat) {
	if (_signed)
		throw AForm::FormIsSignedException();
	if (bureaucrat.getGrade() > _toSign)
		throw Bureaucrat::GradeTooLowException();
	_signed = true;
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char	*AForm::FormIsSignedException::what() const throw() {
	return ("Form is already signed");
}

const char	*AForm::FormIsNotSignedException::what() const throw() {
	return ("Form is not signed");
}

std::ostream	&operator<<(std::ostream &out, AForm &form) {
	out << "Form: " << form.getName() << "\n"
		<< "Status: " << (form.getSigned() ? "signed" : "not signed") << "\n"
		<< "Grade to sign: " << form.getToSign() << "\n"
		<< "Grade to execute: " << form.getToExecute() << std::endl;
	return (out);
}
