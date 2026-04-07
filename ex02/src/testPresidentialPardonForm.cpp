#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <gtest/gtest.h>

TEST(PresidentialPardonForm, constructors) {
	// Default constructor
	EXPECT_NO_THROW({PresidentialPardonForm a;});

	// Copy constructor
	PresidentialPardonForm a;
	EXPECT_NO_THROW({PresidentialPardonForm b(a);});

	// Target constructor
	EXPECT_NO_THROW({PresidentialPardonForm a("John Doe");});
}

TEST(PresidentialPardonForm, execute) {
	AForm *form = new PresidentialPardonForm("John");
	Bureaucrat ok("ok", 1);
	Bureaucrat notOk("notOk", 150);

	EXPECT_THROW({form->execute(ok);}, AForm::FormIsNotSignedException);
	form->beSigned(ok);
	EXPECT_THROW({form->execute(notOk);}, Bureaucrat::GradeTooLowException);
	testing::internal::CaptureStdout();
	form->execute(ok);
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "John was pardoned by Zaphod Beeblebrox\n");
	delete form;
}
