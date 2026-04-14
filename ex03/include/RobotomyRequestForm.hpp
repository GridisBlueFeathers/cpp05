#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# if TEST_ENV
#  ifndef RAND
#   define RAND 1
#  endif
# else 
#  ifndef RAND
#   define RAND rand()
#  endif
# endif


class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm();

		class RoboromyFailException: public std::exception {
			public:
				virtual const char	*what() const throw();	
		};

		void	execute(Bureaucrat const &executor) const;
};

#endif
