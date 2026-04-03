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
	AForm *a = new PresidentialPardonForm("John");
	Bureaucrat ok("ok", 1);
	Bureaucrat notOk("notOk", 150);

	EXPECT_THROW({a->execute(ok);}, AForm::FormIsNotSignedException);
	a->beSigned(ok);
	EXPECT_THROW({a->execute(notOk);}, AForm::GradeTooLowException);
	testing::internal::CaptureStdout();
	a->execute(ok);
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "John was pardoned by Zaphod Beeblebrox\n");
	delete a;
}
