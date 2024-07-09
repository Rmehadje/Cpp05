/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:52:22 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/04 16:15:22 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class	Bureaucrat{
	private:
		const std::string name;
		int	grade;
		Bureaucrat();

	public:
		Bureaucrat(const std::string &Name, int Grade);
		Bureaucrat(const Bureaucrat &og);
		Bureaucrat &operator=(const Bureaucrat &cp);
		~Bureaucrat();

		void	increment(void);
		void	decrement(void);

		const	std::string &getName(void) const;
		int	getGrade(void) const;

		void	signForm(Form &form);
		class GradeTooHighException: public std::exception{
			virtual const char* what(void) const throw() {return "Grade is too high";};
		};
		class GradeTooLowException: public std::exception{
			virtual const char* what(void) const throw() {return "Grade is too low";};
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &value);