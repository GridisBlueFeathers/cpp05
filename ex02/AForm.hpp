/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:18:36 by svereten          #+#    #+#             */
/*   Updated: 2025/09/13 16:10:29 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#ifndef FORM_HPP
# define FORM_HPP

# include <string>

# include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string	_name;
		const std::string	_target;
		const unsigned int	_toSign;
		const unsigned int	_toExecute;
		bool				_signed;
		bool				_executed;

		AForm();
		AForm(const AForm &other);
		AForm				&operator=(const AForm &other);
	public:
		AForm(const std::string &name,
			const std::string &target,
			unsigned int toSign,
			unsigned int toExecute);
		virtual ~AForm();


		const std::string	&getName(void) const;
		const std::string	&getTarget(void) const;
		unsigned int		getToSign(void) const;
		unsigned int		getToExecute(void) const;
		bool				getSigned(void) const;
		bool				getExecuted(void) const;
	
		void				beSigned(Bureaucrat bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const = 0;

		class FormIsSignedException: public std::exception {
			public:
				virtual const char	*what() const throw();	
		};

		class FormIsNotSignedException: public std::exception {
			public:
				virtual const char	*what() const throw();	
		};
};

std::ostream	&operator<<(std::ostream &out, AForm &form);

#endif
