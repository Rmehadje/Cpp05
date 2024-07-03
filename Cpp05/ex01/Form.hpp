/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:57:38 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/03 12:39:15 by rmehadje         ###   ########.fr       */
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
		bool					besign;
		const int			gradeSign;
		const int			gradeExec;
	public:
		Form(const std::string name, int gradeSign);
		Form(const std::string name, int gradeSign, int gradeExec);
		~Form();
		Form(const Form &og);
		Form &operator=(const Form &cp);

		std::string	getName() const;
		bool			beSign() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		void			beSigned(const Bureaucrat &Bureaucrat);

		class GradeTooHighException: public std::exception{
			const char* what(void) const throw();
		};
		class GradeTooLowException: public std::exception{
			const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &value);
