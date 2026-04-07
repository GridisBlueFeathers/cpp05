#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <gtest/gtest.h>

TEST(RobotomyRequestForm, constructors) {
	// Default constructor
	EXPECT_NO_THROW({RobotomyRequestForm a;});

	// Copy constructor
	RobotomyRequestForm a;
	EXPECT_NO_THROW({RobotomyRequestForm b(a);});

	// Target constructor
	EXPECT_NO_THROW({RobotomyRequestForm a("John Doe");});
}

// TEST(RobotomyRequestForm, execute) {
// 	RobotomyRequestForm form("John");
// 	Bureaucrat ok("ok", 1);
// 	Bureaucrat notOk("notOk", 150);
//
// 	EXPECT_THROW({form.execute(ok);}, AForm::FormIsNotSignedException);
// 	form.beSigned(ok);
// 	EXPECT_THROW({form.execute(notOk);}, AForm::GradeTooLowException);
// 	if (RAND % 2) {
// 		testing::internal::CaptureStdout();
// 		form.execute(ok);
// 		std::string output = testing::internal::GetCapturedStdout();
// 		EXPECT_EQ(output, "John was sucessfully robotomized!\n");
// 	} else {
// 		EXPECT_THROW({form.execute(ok);}, RobotomyRequestForm::RoboromyFailException);
// 	}
// }

TEST(RobotomyRequestForm, execute) {
	AForm *form = new RobotomyRequestForm("John");
	Bureaucrat ok("ok", 1);
	Bureaucrat notOk("notOk", 150);

	EXPECT_THROW({form->execute(ok);}, AForm::FormIsNotSignedException);
	form->beSigned(ok);
	EXPECT_THROW({form->execute(notOk);}, AForm::GradeTooLowException);
	if (RAND % 2) {
		testing::internal::CaptureStdout();
		form->execute(ok);
		std::string output = testing::internal::GetCapturedStdout();
		EXPECT_EQ(output, "John was sucessfully robotomized!\n");
	} else {
		EXPECT_THROW({form->execute(ok);}, RobotomyRequestForm::RoboromyFailException);
	}
	delete form;
}
