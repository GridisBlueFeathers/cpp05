#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include <sys/stat.h>

TEST(ShrubberyCreationForm, constructors) {
	// Default constructor
	EXPECT_NO_THROW({ShrubberyCreationForm a;});

	// Copy constructor
	ShrubberyCreationForm a;
	EXPECT_NO_THROW({ShrubberyCreationForm b(a);});

	// Target constructor
	EXPECT_NO_THROW({ShrubberyCreationForm a("John Doe");});
}

TEST(ShrubberyCreationForm, execute) {
	AForm *form = new ShrubberyCreationForm("John");
	Bureaucrat ok("ok", 1);
	Bureaucrat notOk("notOk", 150);

	EXPECT_THROW({form->execute(ok);}, AForm::FormIsNotSignedException);
	form->beSigned(ok);
	EXPECT_THROW({form->execute(notOk);}, Bureaucrat::GradeTooLowException);
	form->execute(ok);

	std::fstream file("John_shrubbery");
	std::string shrubbery;
	std::string tmp;

	while (std::getline(file, tmp)) {
		shrubbery += tmp;
		shrubbery += "\n";
	}
	shrubbery.pop_back();

	EXPECT_EQ(shrubbery, SHRUBERRY);

	chmod("John_shrubbery", 0000);
	testing::internal::CaptureStderr();
	form->execute(ok);
	std::string output = testing::internal::GetCapturedStderr();
	EXPECT_EQ(output, "Shrubbery creation failed :(\n");
	chmod("John_shrubbery", 0644);
	remove("John_shrubbery");

	delete form;
}
