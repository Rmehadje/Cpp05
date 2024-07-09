/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:50:07 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/05 13:47:02 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class PresidentialPardonForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;

class Intern{
	public:
		Intern();
		Intern(Intern const &og);
		~Intern();

	Intern &operator=(Intern const &cp);
	
	class NoFormFound: public std::exception{
		public:
		virtual const char *what(void) const throw();
	};
	AForm	*makeForm(std::string const &formname, std::string target);
};