/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:52:22 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/05 13:37:06 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

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
		void	setGrade(int grade);

		void	signForm(AForm &Aform);
		void	executeForm(AForm const &Aform);
		class GradeTooHighException: public std::exception{
			virtual const char* what(void) const throw() {return "Grade is too high";};
		};
		class GradeTooLowException: public std::exception{
			virtual const char* what(void) const throw() {return "Grade is too low";};
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &value);