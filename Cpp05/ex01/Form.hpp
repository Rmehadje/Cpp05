/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:57:38 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/09 13:59:59 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form{
	private:
		const	std::string name;
		bool					isitSigned;
		const int			gradeSign;
		const int			gradeExec;
		Form(const std::string name, int gradeSign, int gradeExec);
	public:
		~Form();
		Form(const Form &og);
		Form &operator=(const Form &cp);

		std::string	getName() const;
		bool			getSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;

		void			beSigned(const Bureaucrat &Bureaucrat);

		class GradeTooHighException: public std::exception{
			public:
			virtual const char* what(void) const throw() { return "grade too high";};
		};
		class GradeTooLowException: public std::exception{
			public:
			virtual const char* what(void) const throw() { return "grade too low";};
		};
};

std::ostream &operator<<(std::ostream &out, const Form &value);
