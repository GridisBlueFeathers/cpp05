/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:59:06 by svereten          #+#    #+#             */
/*   Updated: 2026/04/14 13:56:13 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat	john("John", 5);
	Intern		intern;
	AForm		*robotomy = intern.makeForm("robotomy request", "john doe");
	AForm		*shruberry = intern.makeForm("shrubbery creation", "newLocation");
	AForm		*pardon = intern.makeForm("presidential pardon", "john");
	
	std::cerr << *robotomy;
	john.signForm(*robotomy);
	std::cerr << *robotomy;
	john.executeForm(*robotomy);

	std::cerr << *shruberry;
	john.signForm(*shruberry);
	std::cerr << *shruberry;
	john.executeForm(*shruberry);

	std::cerr << *pardon;
	john.signForm(*pardon);
	std::cerr << *pardon;
	john.executeForm(*pardon);

	delete robotomy;
}
