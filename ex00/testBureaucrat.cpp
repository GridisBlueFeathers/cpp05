/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testBureaucrat.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:32:32 by svereten          #+#    #+#             */
/*   Updated: 2025/06/05 17:09:34 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include <gtest/gtest.h>
#include <exception>

TEST(Bureaucrat, constructors) {
	Bureaucrat a;
	Bureaucrat b("Johnny", 150);

	EXPECT_THROW(Bureaucrat tooLow("Low", 151), Bureaucrat::GradeTooLowException);
	EXPECT_THROW(Bureaucrat tooHigh("High", 0), Bureaucrat::GradeTooLowException);
}
