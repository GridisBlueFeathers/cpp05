/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:18:24 by svereten          #+#    #+#             */
/*   Updated: 2026/02/06 14:33:07 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat {
private:
	const std::string	_name;
	unsigned int		_grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat(const std::string &name, unsigned int rank);
	~Bureaucrat();

	Bureaucrat			&operator=(const Bureaucrat &other);

	const std::string	&getName(void) const;
	unsigned int		getGrade(void) const;

	void				increaseGrade(void);
	void				decreaseGrade(void);

	class GradeTooHighException: public std::exception {
		public:
			virtual const char	*what() const throw();
	};

	class GradeTooLowException: public std::exception {
		public:
			virtual const char	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat bureaucrat);

#endif 
