/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:59:06 by svereten          #+#    #+#             */
/*   Updated: 2026/02/27 11:37:52 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	Bureaucrat	john("John", 25);
	AForm		*form = new RobotomyRequestForm("john doe");
	
	std::cerr << *form;
	john.signForm(*form);
	std::cerr << *form;
	john.executeForm(*form);
	delete form;
}
