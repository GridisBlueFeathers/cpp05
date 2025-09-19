/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:18:36 by svereten          #+#    #+#             */
/*   Updated: 2025/09/19 14:13:02 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#ifndef FORM_HPP
# define FORM_HPP

# include <string>

# include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_toSign;
		const unsigned int	_toExecute;

	public:
		Form();
		Form(const Form &other);
		Form(const std::string &name, unsigned int toSign, unsigned int toExecute);
		~Form();

		Form				&operator=(const Form &other);

		const std::string	&getName(void) const;
		bool				getSigned(void) const;
		unsigned int		getToSign(void) const;
		unsigned int		getToExecute(void) const;
	
		void				beSigned(Bureaucrat bureaucrat);

		class GradeTooLowException: public std::exception {
			public:
				virtual const char	*what() const throw();	
		};

		class GradeTooHighException: public std::exception {
			public:
				virtual const char	*what() const throw();	
		};

		class IsSignedException: public std::exception {
			public:
				virtual const char	*what() const throw();	
		};
};

std::ostream	&operator<<(std::ostream &out, Form form);

#endif
