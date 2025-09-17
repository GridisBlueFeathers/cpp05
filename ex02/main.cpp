/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:59:06 by svereten          #+#    #+#             */
/*   Updated: 2025/09/13 15:18:49 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
	Bureaucrat	john("John", 69);
	AForm		form("aaa", 69, 69);
	
	std::cerr << form;
	john.signForm(form);
	std::cerr << form;
}
