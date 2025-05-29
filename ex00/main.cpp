/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:59:06 by svereten          #+#    #+#             */
/*   Updated: 2025/05/29 15:19:11 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b("John Doe", 150);
		std::cout << b;
		b.decreaseGrade();
		std::cout << b;
		b.decreaseGrade();
		std::cout << b;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
