#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <gtest/gtest.h>

TEST(Intern, constructors) {
	// Default constructor
	EXPECT_NO_THROW({Intern a;});

	// Copy constructor
	Intern a;
	EXPECT_NO_THROW({Intern b(a);});
}

TEST(Intern, makeForm) {
	Intern intern;
	AForm *form = intern.makeForm("presidential pardon", "John");

	EXPECT_NE(dynamic_cast<PresidentialPardonForm *>(form), (void *)0x0);
	
	delete form;
	
	form = intern.makeForm("shrubbery creation", "John");

	EXPECT_NE(dynamic_cast<ShrubberyCreationForm *>(form), (void *)0x0);
	
	delete form;

	form = intern.makeForm("robotomy request", "John");

	EXPECT_NE(dynamic_cast<RobotomyRequestForm *>(form), (void *)0x0);
	
	delete form;

	EXPECT_THROW({
		AForm *nonexistant = intern.makeForm("Huh", "John");
		delete nonexistant;
	}, Intern::FormNotFoundException);
}
