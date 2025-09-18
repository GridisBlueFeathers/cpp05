/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testAForm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:32:02 by svereten          #+#    #+#             */
/*   Updated: 2025/09/13 15:55:03 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AForm.hpp"
#include <gtest/gtest.h>

/**
 * Abstract form can not be instantiated by itself
 */
// TEST(form, constructors) {
// 	// Default constructor
// 	EXPECT_NO_THROW({AForm a;});
//
// 	// Copy constructor
// 	AForm a;
// 	EXPECT_NO_THROW({AForm b(a);});
//
// 	// Name, toSign, toExecute constructor
// 	EXPECT_NO_THROW({AForm b("AForm", 150, 150);});
//
// 	EXPECT_THROW({AForm tooLowToSign("LowToSign", 151, 150);},
// 		Bureaucrat::GradeTooLowException);
// 	EXPECT_THROW({AForm tooLowToExecute("LowToExecute", 150, 151);},
// 		Bureaucrat::GradeTooLowException);
// 	EXPECT_THROW({AForm tooLowBoth("LowBoth", 151, 151);},
// 		Bureaucrat::GradeTooLowException);
// 	EXPECT_THROW({AForm tooHighToSign("HighToSign", 0, 1);},
// 		Bureaucrat::GradeTooHighException);
// 	EXPECT_THROW({AForm tooHighToExecute("HighToExecute", 1, 0);},
// 		Bureaucrat::GradeTooHighException);
// 	EXPECT_THROW({AForm tooHighBoth("HighBoth", 0, 0);},
// 		Bureaucrat::GradeTooHighException);
// }

TEST(form, operators) {
	// Assignment operator shouldn't work with abstract classes
	// AForm a("A", 1, 1);
	//
	// EXPECT_NO_THROW({AForm b = a;});
	// AForm b = a;
	// EXPECT_EQ(b.getName(), a.getName());
	// EXPECT_EQ(b.getSigned(), a.getSigned());
	// EXPECT_EQ(b.getToSign(), a.getToSign());
	// EXPECT_EQ(b.getToExecute(), a.getToExecute());

	// Stream insertion operator
	testing::internal::CaptureStdout();
	std::cout << a;
	std::string out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "Form: A\nStatus: not signed\nGrade to sign: 1\nGrade to execute: 1\n");
}

TEST(form, getters) {
	AForm a("AForm", 42, 69);

	EXPECT_EQ(a.getName(), "AForm");
	EXPECT_EQ(a.getSigned(), false);
	EXPECT_EQ(a.getToSign(), 42);
	EXPECT_EQ(a.getToExecute(), 69);
}

TEST(form, beSigned) {
	AForm a("AForm", 42, 69);
	Bureaucrat tooLow("tooLow", 150);
	Bureaucrat ok("ok", 42);

	EXPECT_THROW({a.beSigned(tooLow);}, Bureaucrat::GradeTooLowException);
	EXPECT_NO_THROW({a.beSigned(ok);});
	EXPECT_THROW({a.beSigned(ok);}, AForm::FormIsSignedException);
}
