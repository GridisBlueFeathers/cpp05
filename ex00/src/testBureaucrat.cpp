/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testBureaucrat.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:32:32 by svereten          #+#    #+#             */
/*   Updated: 2025/06/14 13:01:02 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include <gtest/gtest.h>
#include <exception>

TEST(Bureaucrat, constructors) {
	// Default constructor
	EXPECT_NO_THROW({Bureaucrat a;});

	// Copy constructor
	Bureaucrat a;
	EXPECT_NO_THROW({Bureaucrat b(a);});

	// Name, Grade constructor
	EXPECT_NO_THROW({Bureaucrat b("Johnny", 150);});

	EXPECT_THROW({Bureaucrat tooLow("Low", 151);}, Bureaucrat::GradeTooLowException);
	EXPECT_THROW({Bureaucrat tooHigh("High", 0);}, Bureaucrat::GradeTooHighException);
}

TEST(Bureaucrat, operators) {
	// Assignment operator
	Bureaucrat a("A", 1);

	EXPECT_NO_THROW({Bureaucrat b = a;});
	Bureaucrat b = a;
	EXPECT_EQ(b.getName(), a.getName());
	EXPECT_EQ(b.getGrade(), a.getGrade());

	// Stream insertion operator
	testing::internal::CaptureStdout();
	std::cout << a;
	std::string out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "A, bureaucrat grade 1.");
}

TEST(Bureaucrat, getters) {
	Bureaucrat a("Johnny", 42);

	EXPECT_EQ(a.getName(), "Johnny");
	EXPECT_EQ(a.getGrade(), 42);
}

TEST(Bureaucrat, gradeMutation) {
	Bureaucrat high("High", 2);
	Bureaucrat low("low", 149);

	EXPECT_NO_THROW({high.increaseGrade();});
	EXPECT_EQ(high.getGrade(), 1);
	EXPECT_THROW({high.increaseGrade();}, Bureaucrat::GradeTooHighException);

	EXPECT_NO_THROW({low.decreaseGrade();});
	EXPECT_EQ(low.getGrade(), 150);
	EXPECT_THROW({low.decreaseGrade();}, Bureaucrat::GradeTooLowException);

}
