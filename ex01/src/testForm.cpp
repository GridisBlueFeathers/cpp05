/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:32:02 by svereten          #+#    #+#             */
/*   Updated: 2026/02/06 14:48:35 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <gtest/gtest.h>

TEST(form, constructors) {
	// Default constructor
	EXPECT_NO_THROW({Form a;});

	// Copy constructor
	Form a;
	EXPECT_NO_THROW({Form b(a);});

	// Name, toSign, toExecute constructor
	EXPECT_NO_THROW({Form b("Form", 150, 150);});

	EXPECT_THROW({Form tooLowToSign("LowToSign", 151, 150);},
		Form::GradeTooLowException);
	EXPECT_THROW({Form tooLowToExecute("LowToExecute", 150, 151);},
		Form::GradeTooLowException);
	EXPECT_THROW({Form tooLowBoth("LowBoth", 151, 151);},
		Form::GradeTooLowException);
	EXPECT_THROW({Form tooHighToSign("HighToSign", 0, 1);},
		Form::GradeTooHighException);
	EXPECT_THROW({Form tooHighToExecute("HighToExecute", 1, 0);},
		Form::GradeTooHighException);
	EXPECT_THROW({Form tooHighBoth("HighBoth", 0, 0);},
		Form::GradeTooHighException);
}

TEST(form, operators) {
	// Assignment operator
	Form a("A", 1, 1);

	EXPECT_NO_THROW({Form b = a;});
	Form b = a;
	EXPECT_EQ(b.getName(), a.getName());
	EXPECT_EQ(b.getSigned(), a.getSigned());
	EXPECT_EQ(b.getToSign(), a.getToSign());
	EXPECT_EQ(b.getToExecute(), a.getToExecute());

	// Stream insertion operator
	testing::internal::CaptureStdout();
	std::cout << a;
	std::string out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "Form: A\nStatus: not signed\nGrade to sign: 1\nGrade to execute: 1\n");
}

TEST(form, getters) {
	Form a("Form", 42, 69);

	EXPECT_EQ(a.getName(), "Form");
	EXPECT_EQ(a.getSigned(), false);
	EXPECT_EQ(a.getToSign(), 42);
	EXPECT_EQ(a.getToExecute(), 69);
}

TEST(form, beSigned) {
	Form a("Form", 42, 69);
	Bureaucrat tooLow("tooLow", 150);
	Bureaucrat ok("ok", 42);

	EXPECT_THROW({a.beSigned(tooLow);}, Form::GradeTooLowException);
	EXPECT_NO_THROW({a.beSigned(ok);});
	EXPECT_THROW({a.beSigned(ok);}, Form::IsSignedException);
}
